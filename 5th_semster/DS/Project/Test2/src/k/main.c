/*
 * main.c — Stock Market Order Matching Engine
 *          Baseline (Linked List)  vs  Optimised (RBTree + FibHeap)
 *
 * Program flow:
 *   1. run_demo(100)         — process 100 orders with verbose output
 *   2. run_perf_comparison() — benchmark both systems at sizes
 *                              100 / 500 / 1000 / 2000
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/order.h"
#include "../lib/trade.h"
#include "../lib/baseline.h"
#include "../lib/optimized.h"
#include "../lib/scenario.h"
#include "../lib/performance.h"

/* Maximum trades one order can generate in a single process() call.
   With qty up to 500 and 2000 orders, this is conservative.         */
#define MAX_TRADES_PER_ORDER  512

/* Fixed seed ensures both systems see the same orders */
#define RNG_SEED  42U

/* ================================================================== */
/*  Helper: run baseline silently, return elapsed ms                  */
/* ================================================================== */
static double bench_baseline(const Order *orders, int n) {
    BaselineBook *bk = baseline_create();
    Trade         trades[MAX_TRADES_PER_ORDER];
    Timer         t;

    timer_start(&t);
    for (int i = 0; i < n; i++)
        baseline_process(bk, orders[i], trades, 0 /*silent*/);
    timer_stop(&t);

    double ms = timer_elapsed_ms(&t);
    baseline_destroy(bk);
    return ms;
}

/* ================================================================== */
/*  Helper: run optimised silently, return elapsed ms                 */
/* ================================================================== */
static double bench_optimized(const Order *orders, int n) {
    OptimizedBook *bk = opt_create();
    Trade          trades[MAX_TRADES_PER_ORDER];
    Timer          t;

    timer_start(&t);
    for (int i = 0; i < n; i++)
        opt_process(bk, orders[i], trades, 0 /*silent*/);
    timer_stop(&t);

    double ms = timer_elapsed_ms(&t);
    opt_destroy(bk);
    return ms;
}

/* ================================================================== */
/*  Demo: run both systems on `n` orders with verbose trade output    */
/* ================================================================== */
static void run_demo(int n) {
    printf("\n");
    printf("+============================================================+\n");
    printf("|  DEMO - Processing %4d orders (seed=%u)              |\n",
           n, RNG_SEED);
    printf("+============================================================+\n");

    Order *orders = generate_orders(n, RNG_SEED);

    /* Print scenario summary */
    printf("\n[Scenario]\n");
    scenario_print_summary(orders, n);

    /* Show first 8 orders */
    printf("\n[First 8 orders]\n");
    int show = (n < 8) ? n : 8;
    for (int i = 0; i < show; i++) order_print(&orders[i]);

    /* ---- BASELINE ---- */
    printf("\n[Baseline - first 10 trades printed]\n");
    {
        BaselineBook *bk    = baseline_create();
        Trade         trades[MAX_TRADES_PER_ORDER];
        int           shown = 0;
        Timer         t;

        timer_start(&t);
        for (int i = 0; i < n; i++) {
            int cnt = baseline_process(bk, orders[i], trades,
                                       /*verbose=*/ (shown < 10) ? 1 : 0);
            shown  += cnt;
        }
        timer_stop(&t);

        printf("\n  [Baseline] Final book state:\n");
        baseline_print_top5(bk);
        printf("  Trades executed : %d\n",  bk->matched_trades);
        printf("  Total qty matched: %ld\n", bk->total_matched_qty);
        printf("  Pending orders  : %d\n",  baseline_pending(bk));
        printf("  Elapsed         : %.4f ms\n", timer_elapsed_ms(&t));

        baseline_destroy(bk);
    }

    /* ---- OPTIMISED ---- */
    printf("\n[Optimised - first 10 trades printed]\n");
    {
        OptimizedBook *bk    = opt_create();
        Trade          trades[MAX_TRADES_PER_ORDER];
        int            shown = 0;
        Timer          t;

        timer_start(&t);
        for (int i = 0; i < n; i++) {
            int cnt = opt_process(bk, orders[i], trades,
                                  /*verbose=*/ (shown < 10) ? 1 : 0);
            shown  += cnt;
        }
        timer_stop(&t);

        /* Process expiry: pretend current_time = n + ORDER_EXPIRY_OFFSET */
        opt_process_expired(bk, (long)n + ORDER_EXPIRY_OFFSET);

        printf("\n  [Optimised] Final book state:\n");
        opt_print_top5(bk);
        printf("  Trades executed : %d\n",  bk->matched_trades);
        printf("  Total qty matched: %ld\n", bk->total_matched_qty);
        printf("  Pending price lvls: %d\n", opt_pending(bk));
        printf("  Elapsed         : %.4f ms\n", timer_elapsed_ms(&t));

        opt_destroy(bk);
    }

    free(orders);
}

/* ================================================================== */
/*  Validation: both systems should produce the same trade count      */
/* ================================================================== */
static void validate(int n) {
    Order *orders = generate_orders(n, RNG_SEED);

    /* Baseline counts */
    BaselineBook *bl = baseline_create();
    Trade trades[MAX_TRADES_PER_ORDER];
    for (int i = 0; i < n; i++)
        baseline_process(bl, orders[i], trades, 0);
    int bl_trades = bl->matched_trades;
    long bl_qty   = bl->total_matched_qty;
    baseline_destroy(bl);

    /* Optimised counts */
    OptimizedBook *op = opt_create();
    for (int i = 0; i < n; i++)
        opt_process(op, orders[i], trades, 0);
    int op_trades = op->matched_trades;
    long op_qty   = op->total_matched_qty;
    opt_destroy(op);

    free(orders);

    printf("  n=%-5d  BL trades=%-5d  OPT trades=%-5d  "
           "BL qty=%-7ld  OPT qty=%-7ld  %s\n",
           n, bl_trades, op_trades, bl_qty, op_qty,
           (bl_trades == op_trades && bl_qty == op_qty) ? "OK [PASS]" : "FAIL [MISMATCH]");
}

/* ================================================================== */
/*  Performance comparison table                                      */
/* ================================================================== */
static void run_perf_comparison(void) {
    int sizes[]    = {100, 500, 1000, 2000};
    int num_sizes  = 4;

    /* Run each size multiple times and take the minimum (warmup effect) */
    int REPS = 5;

    printf("\n");
    printf("+===================================================================+\n");
    printf("|                  PERFORMANCE COMPARISON TABLE                   |\n");
    printf("|  (best of %d runs per size, same random seed=%u)               |\n",
           REPS, RNG_SEED);
    printf("+===========+=================+=================+==================+\n");
    printf("|  Orders   |  Baseline (ms)  |  Optimised (ms) |  Speedup         |\n");
    printf("+===========+=================+=================+==================+\n");

    for (int s = 0; s < num_sizes; s++) {
        int    n      = sizes[s];
        Order *orders = generate_orders(n, RNG_SEED);

        double bl_best  = 1e18, opt_best = 1e18;
        for (int r = 0; r < REPS; r++) {
            double bl  = bench_baseline(orders, n);
            double opt = bench_optimized(orders, n);
            if (bl  < bl_best)  bl_best  = bl;
            if (opt < opt_best) opt_best = opt;
        }
        free(orders);

        double speedup = (opt_best > 1e-9) ? bl_best / opt_best : 0.0;
        printf("|  %-7d |  %13.4f  |  %13.4f  |  %6.2fx faster    |\n",
               n, bl_best, opt_best, speedup);
    }
    printf("+===========+=================+=================+==================+\n");
    printf("\nNote: Optimised is faster for large n due to O(log n) vs O(n)\n"
           "      tree traversal.  At small n, constant factors may dominate.\n");
}

/* ================================================================== */
/*  main                                                              */
/* ================================================================== */
int main(void) {
    printf("+===================================================================+\n");
    printf("|   Stock Market Order Matching Engine                            |\n");
    printf("|   Baseline: Sorted Linked List                                  |\n");
    printf("|   Optimised: Red-Black Tree (price) + Fibonacci Heap (expiry)  |\n");
    printf("+===================================================================+\n");

    /* ---- 1. Correctness validation -------------------------------- */
    printf("\n[Validation - both systems must produce identical trade counts]\n");
    int val_sizes[] = {50, 100, 500, 1000};
    for (int i = 0; i < 4; i++) validate(val_sizes[i]);

    /* ---- 2. Demo with verbose output ------------------------------ */
    run_demo(100);

    /* ---- 3. Performance benchmark table --------------------------- */
    run_perf_comparison();

    printf("\nDone.\n");
    return 0;
}
