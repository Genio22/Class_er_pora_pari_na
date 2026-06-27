/**
 * @license
 * SPDX-License-Identifier: Apache-2.0
 */

import { RobotConfig, OpponentType, ArenaSettings } from './types';
import { getDefaultSensors, getDefaultAiCode } from './simulationEngine';

export const DEFAULT_OPPONENTS: OpponentType[] = [
  {
    id: 'opp_dummy',
    name: 'Practice Pillar (Dummy)',
    description: 'A heavy, non-moving practice post. Perfect for testing raw sensor coverage and basic push-out force.',
    type: 'dummy',
    width: 12,
    length: 12,
    weight: 1000,
    maxSpeed: 0,
    color: '#4b5563' // gray
  },
  {
    id: 'opp_random',
    name: 'Wandering Nomad (Random)',
    description: 'Drives around in smooth arcs, reversing blindly whenever it senses any white ring boundary.',
    type: 'random',
    width: 10,
    length: 10,
    weight: 450,
    maxSpeed: 60,
    color: '#3b82f6' // blue
  },
  {
    id: 'opp_spinner',
    name: 'Cyclone Spinner (Spinner)',
    description: 'Spins continuously in place, launching a full-power direct strike the moment something crosses its vision.',
    type: 'spinner',
    width: 10,
    length: 10,
    weight: 480,
    maxSpeed: 75,
    color: '#8b5cf6' // purple
  },
  {
    id: 'opp_defensive',
    name: 'Centurion Guard (Defensive)',
    description: 'Actively navigates to the exact center. Rotates slowly to scan and launches shoves only when provoked.',
    type: 'defensive',
    width: 10.5,
    length: 10.5,
    weight: 495,
    maxSpeed: 55,
    color: '#10b981' // green
  },
  {
    id: 'opp_aggressive',
    name: 'Wild Bull (Aggressive)',
    description: 'Hunts aggressively by scanning with sonar networks. If detected, charges immediately at 100% torque.',
    type: 'aggressive',
    width: 10,
    length: 10,
    weight: 500,
    maxSpeed: 85,
    color: '#ef4444' // red
  },
  {
    id: 'opp_camper',
    name: 'Edge Lurker (Border Patrol)',
    description: 'Patrols around the white borders of the ring, trying to bait you into flying off and losing balance.',
    type: 'edge_camper',
    width: 9.8,
    length: 9.8,
    weight: 460,
    maxSpeed: 65,
    color: '#f59e0b' // yellow
  },
  {
    id: 'opp_competitive',
    name: 'Grandmaster Bot (Competitive)',
    description: 'An advanced state-machine implementation that utilizes active tracking, edge avoidance, and strategic orbits.',
    type: 'competitive',
    width: 10,
    length: 10,
    weight: 500,
    maxSpeed: 80,
    color: '#ec4899' // pink
  },
  {
    id: 'opp_custom',
    name: 'Custom User AI (Custom)',
    description: 'Write your own opponent code and sensors.',
    type: 'custom',
    width: 10,
    length: 10,
    weight: 450,
    maxSpeed: 80,
    color: '#06b6d4', // cyan
    aiCode: `function robotLogic(sensorData, robotState, state) {
  // Simple pursuit custom opponent
  if(sensorData.opp_tof < 40 || sensorData.opp_sonar_l < 40 || sensorData.opp_sonar_r < 40) {
    return { leftMotor: 255, rightMotor: 255, stateLabel: 'ATTACK' };
  }
  return { leftMotor: 50, rightMotor: -50, stateLabel: 'SCAN' };
}`
  }
];

export const DEFAULT_ARENA: ArenaSettings = {
  diameter: 77, // Standard Mini Sumo 77cm doh-yo
  edgeWidth: 2.5, // 2.5cm White border line
  friction: 0.8,  // Clean wooden floor friction coefficient
  ringColor: '#1f2937', // dark slate
  edgeColor: '#f9fafb'  // white
};

export const SAMPLE_AI_PRESETS = [
  {
    name: 'Step-Search & Turn-to-Lock',
    description: 'Searches by stepping: spin, forward, spin, backward. Locks onto side targets.',
    code: `function robotLogic(sensorData, robotState, state) {
  if (!state.mode) {
    state.mode = 'SEARCH_SPIN_1';
    state.navTimer = 0;
    state.lastTargetDir = 1;
    state.lostTicks = 0;
  }

  const edgeFL = sensorData.edge_fl || 0;
  const edgeFR = sensorData.edge_fr || 0;
  const edgeRL = sensorData.edge_rl || 0;
  const edgeRR = sensorData.edge_rr || 0;
  const frontTof = sensorData.tof_f !== undefined ? sensorData.tof_f : 999;
  const leftSonar = sensorData.sonar_l !== undefined ? sensorData.sonar_l : 999;
  const rightSonar = sensorData.sonar_r !== undefined ? sensorData.sonar_r : 999;

  // PRIORITY 1: EDGE ESCAPE
  const isEdgeDetected = edgeFL > 0.5 || edgeFR > 0.5 || edgeRL > 0.5 || edgeRR > 0.5;
  if (isEdgeDetected && state.mode !== 'EDGE_ESCAPE') {
    state.mode = 'EDGE_ESCAPE';
    state.ticks = 0;
    if (edgeFL > 0.5 && edgeFR > 0.5) state.escapeType = 'BACK_STRAIGHT';
    else if (edgeFL > 0.5) state.escapeType = 'BACK_RIGHT';
    else if (edgeFR > 0.5) state.escapeType = 'BACK_LEFT';
    else if (edgeRL > 0.5 || edgeRR > 0.5) state.escapeType = 'FORWARD';
    else state.escapeType = 'BACK_STRAIGHT';
  }

  if (state.mode === 'EDGE_ESCAPE') {
    state.ticks++;
    if (state.ticks < 15) {
      if (state.escapeType === 'FORWARD') return { leftMotor: 255, rightMotor: 255, stateLabel: "EDGE_ESCAPE (Forward)" };
      return { leftMotor: -255, rightMotor: -255, stateLabel: "EDGE_ESCAPE (Reverse)" };
    } else if (state.ticks < 40) {
      if (state.escapeType === 'BACK_RIGHT') return { leftMotor: 255, rightMotor: -255, stateLabel: "EDGE_ESCAPE (Turn Right)" };
      if (state.escapeType === 'BACK_LEFT') return { leftMotor: -255, rightMotor: 255, stateLabel: "EDGE_ESCAPE (Turn Left)" };
      return { leftMotor: 255, rightMotor: -255, stateLabel: "EDGE_ESCAPE (Turn Right)" };
    } else {
      state.mode = 'SEARCH_SPIN_1';
      state.navTimer = 0;
    }
  }

  // PRIORITY 2: ATTACK
  if (frontTof < 100) {
    state.mode = 'ATTACK';
    state.lastTargetDir = 0;
    state.lostTicks = 0;
    return { leftMotor: 255, rightMotor: 255, stateLabel: "ATTACK (Charge)" };
  }

  // PRIORITY 3: LOCK
  // "when left hit turn left slightly, right hit turn right slightly"
  if (leftSonar < 80) {
    state.mode = 'LOCK_LEFT';
    state.lastTargetDir = -1;
    state.lostTicks = 0;
    return { leftMotor: -140, rightMotor: 200, stateLabel: "LOCK (Turn Left)" };
  }
  
  if (rightSonar < 80) {
    state.mode = 'LOCK_RIGHT';
    state.lastTargetDir = 1;
    state.lostTicks = 0;
    return { leftMotor: 200, rightMotor: -140, stateLabel: "LOCK (Turn Right)" };
  }

  // PRIORITY 4: LOST TARGET
  if (['ATTACK', 'LOCK_LEFT', 'LOCK_RIGHT', 'LOST_TARGET'].includes(state.mode)) {
    state.mode = 'LOST_TARGET';
    state.lostTicks = (state.lostTicks || 0) + 1;
    if (state.lostTicks < 40) {
      if (state.lastTargetDir === -1) return { leftMotor: -100, rightMotor: 100, stateLabel: "LOST_TARGET (Search Left)" };
      if (state.lastTargetDir === 1) return { leftMotor: 100, rightMotor: -100, stateLabel: "LOST_TARGET (Search Right)" };
      return { leftMotor: 100, rightMotor: 100, stateLabel: "LOST_TARGET (Search Front)" };
    } else {
      state.mode = 'SEARCH_SPIN';
    }
  }

  // PRIORITY 5: SEARCH (Spin 360 Moderately Slow)
  state.mode = 'SEARCH_SPIN';
  return { leftMotor: 100, rightMotor: -100, stateLabel: "SEARCH (Spin 360)" };
}`
  },
  {
    name: 'Spin and Attack(Ahnaf)',
    description: 'A Lock-and-Charge strategy. Rotates to find target, locks on, and charges. Replaces orbit search.',
    code: getDefaultAiCode()
  },
  {
    name: 'Pure Passive Baiter (Defensive Centered)',
    description: 'Avoids attacks, stays in the center, and launches swift, full-torque counter-strikes when approached.',
    code: `/**
 * Pure Passive Baiter AI Strategy
 */
function robotLogic(sensorData, robotState, state) {
  // Initialize state keys
  if (state.timer === undefined) {
    state.timer = 0;
  }

  const edgeFL = sensorData.edge_fl || 0;
  const edgeFR = sensorData.edge_fr || 0;
  const frontTof = sensorData.tof_f || 999;
  const leftSonar = sensorData.sonar_l || 999;
  const rightSonar = sensorData.sonar_r || 999;

  // 1. Edge takes precedence
  if (edgeFL > 0.4 || edgeFR > 0.4) {
    return { leftMotor: -150, rightMotor: -180, stateLabel: "ESC_EDGE" };
  }

  // 2. If opponent detected close (< 35cm), strike full power!
  if (frontTof < 35 || leftSonar < 30 || rightSonar < 30) {
    return { leftMotor: 255, rightMotor: 255, stateLabel: "COUNTER_STRIKE" };
  }

  // 3. Otherwise try to drift back or hold near the center (0,0)
  const px = robotState.position.x;
  const py = robotState.position.y;
  const currentDist = Math.hypot(px, py);

  if (currentDist > 8) {
    // calculate angle to center (0,0)
    const angleToCtr = Math.atan2(-py, -px);
    let headingDiff = angleToCtr - robotState.heading;
    while (headingDiff < -Math.PI) headingDiff += Math.PI * 2;
    while (headingDiff > Math.PI) headingDiff -= Math.PI * 2;

    if (Math.abs(headingDiff) > 0.2) {
      // align to center
      return {
        leftMotor: headingDiff > 0 ? 100 : -100,
        rightMotor: headingDiff > 0 ? -100 : 100,
        stateLabel: "RETREAT_ALIGN"
      };
    } else {
      // cruise to center
      return { leftMotor: 110, rightMotor: 110, stateLabel: "RETREAT_GO" };
    }
  }

  // Slow defensive scanning in place inside center
  return { leftMotor: 40, rightMotor: -40, stateLabel: "CENTER_WATCH" };
}`
  },
  {
    name: 'Berserker Rusher (Aggressive Blind Charge)',
    description: 'Pure speed. Fast search sweeps; once anything is faintly detected, it speeds up to maximum limit in a straight line.',
    code: `/**
 * Berserker Rusher AI Strategy
 */
function robotLogic(sensorData, robotState, state) {
  const edgeFL = sensorData.edge_fl || 0;
  const edgeFR = sensorData.edge_fr || 0;
  const frontTof = sensorData.tof_f || 999;
  const leftSonar = sensorData.sonar_l || 999;
  const rightSonar = sensorData.sonar_r || 999;

  // Tiny edge protection
  if (edgeFL > 0.4 || edgeFR > 0.4) {
    return { leftMotor: -255, rightMotor: -200, stateLabel: "PANIC_REVERSE" };
  }

  // If opponent found anywhere, unleash 100% capacity!
  if (frontTof < 100 || leftSonar < 60 || rightSonar < 60) {
    return { leftMotor: 255, rightMotor: 255, stateLabel: "ENGAGED_SMASH" };
  }

  // Spin extremely fast searching
  return { leftMotor: 200, rightMotor: -200, stateLabel: "RAMPAGE_SEARCH" };
}`
  },
  {
    name: 'Orbiting Stalker (Spiral Arc Patrol)',
    description: 'Orbits around the ring in beautiful curves, avoiding direct front shoves unless the opponent exposes their flank.',
    code: `/**
 * Orbiting Stalker AI Strategy
 */
function robotLogic(sensorData, robotState, state) {
  const edgeFL = sensorData.edge_fl || 0;
  const edgeFR = sensorData.edge_fr || 0;
  const frontTof = sensorData.tof_f || 999;
  const leftSonar = sensorData.sonar_l || 999;
  const rightSonar = sensorData.sonar_r || 999;

  if (edgeFL > 0.45 || edgeFR > 0.45) {
    return { leftMotor: -200, rightMotor: -150, stateLabel: "QUICK_回避" };
  }

  // If opponent gets close on the flanks, pivot and shove
  if (leftSonar < 30) {
    return { leftMotor: -120, rightMotor: 150, stateLabel: "FLANK_HIT_L" };
  }
  if (rightSonar < 30) {
    return { leftMotor: 150, rightMotor: -120, stateLabel: "FLANK_HIT_R" };
  }

  if (frontTof < 45) {
    return { leftMotor: 230, rightMotor: 230, stateLabel: "STALKER_CHARGE" };
  }

  // Wide patrolling arc
  return { leftMotor: 180, rightMotor: 110, stateLabel: "STALK_ARC" };
}`
  },
  {
    name: 'Beginner: Basic Search',
    description: 'Rotates slowly until it finds something, then stops.',
    code: `// Basic Search Example
function robotLogic(sensorData, robotState, state) {
  // Move in a circle
  return { leftMotor: -100, rightMotor: 100, stateLabel: "SEARCH_SPIN" };
}`
  },
  {
    name: 'Beginner: Search & Attack',
    description: 'Spins until a target is detected by the front sensor, then attacks.',
    code: `// Search & Attack Example
function robotLogic(sensorData, robotState, state) {
  const frontTof = sensorData.tof_f || 999;
  
  if (frontTof < 80) { // If target is within 80cm
    return { leftMotor: 255, rightMotor: 255, stateLabel: "ATTACK" };
  }
  
  // Keep searching if no target
  return { leftMotor: -100, rightMotor: 100, stateLabel: "SEARCH" };
}`
  },
  {
    name: 'Intermediate: Search + Attack + Edge Recovery',
    description: 'Full functioning basic robot.',
    code: `// Full Basic Sumo Robot
function robotLogic(sensorData, robotState, state) {
  const edgeFL = sensorData.edge_fl || 0;
  const edgeFR = sensorData.edge_fr || 0;
  const frontTof = sensorData.tof_f || 999;
  const leftSonar = sensorData.sonar_l || 999;
  const rightSonar = sensorData.sonar_r || 999;

  // 1. Edge Protection (Highest Priority)
  if (edgeFL > 0.4 || edgeFR > 0.4) {
    if (state.timer === undefined || state.timer < 5) {
       state.timer = (state.timer || 0) + 1;
       return { leftMotor: -255, rightMotor: -255, stateLabel: "EDGE_ESCAPE" }; // Reverse
    } else if (state.timer < 10) {
       state.timer++;
       return { leftMotor: 200, rightMotor: -200, stateLabel: "EDGE_TURN" }; // Turn away
    } else {
       state.timer = 0; // reset
    }
  } else {
    state.timer = 0;
  }

  // 2. Attack
  if (frontTof < 50) {
    return { leftMotor: 255, rightMotor: 255, stateLabel: "ATTACK_FORWARD" };
  }
  if (leftSonar < 40) {
    return { leftMotor: -150, rightMotor: 255, stateLabel: "ATTACK_LEFT" };
  }
  if (rightSonar < 40) {
    return { leftMotor: 255, rightMotor: -150, stateLabel: "ATTACK_RIGHT" };
  }

  // 3. Search
  return { leftMotor: -150, rightMotor: 150, stateLabel: "SEARCH_SPIN" };
}`
  }
];

export const FACTORY_ROBOTS: RobotConfig[] = [
  {
    id: 'robot_standard',
    name: 'SumoWrecker S-400',
    width: 10,
    length: 10,
    weight: 500,
    cgOffset: 0,
    wheelDiameter: 3.2,
    wheelPosition: 0,
    maxSpeed: 80,
    acceleration: 160,
    deceleration: 220,
    motorTorque: 1.6,
    trackWidth: 9.0,
    batteryVoltage: 7.4,
    batteryCapacity: 350,
    internalResistance: 0.15,
    aiCode: getDefaultAiCode(),
    sensors: getDefaultSensors()
  },
  {
    id: 'robot_heavy',
    name: 'Titan Shove 500S',
    width: 10,
    length: 10,
    weight: 498, // max weights
    cgOffset: -1.5, // rear bias
    wheelDiameter: 3.6,
    wheelPosition: -1.0,
    maxSpeed: 65,
    acceleration: 110,
    deceleration: 190,
    motorTorque: 2.2, // extreme pushing torque
    trackWidth: 9.2,
    batteryVoltage: 8.4, // high voltage cell spec
    batteryCapacity: 500,
    internalResistance: 0.10,
    aiCode: getDefaultAiCode(),
    sensors: [
      { id: 'tof_f', type: 'tof', x: 0, y: 5, rotation: 0, range: 110, fov: 25, updateRate: 60, noise: 0.05, failureProb: 0.01, name: 'Main TOF' },
      { id: 'sonar_l', type: 'sonar', x: -4, y: 5, rotation: -20, range: 80, fov: 32, updateRate: 40, noise: 0.12, failureProb: 0.015, name: 'Sway Sonar L' },
      { id: 'sonar_r', type: 'sonar', x: 4, y: 5, rotation: 20, range: 80, fov: 32, updateRate: 40, noise: 0.12, failureProb: 0.015, name: 'Sway Sonar R' },
      { id: 'edge_fl', type: 'edge', x: -4.5, y: 4.8, rotation: 0, range: 1, fov: 0, updateRate: 100, noise: 0.01, failureProb: 0, name: 'Front-Left Line' },
      { id: 'edge_fr', type: 'edge', x: 4.5, y: 4.8, rotation: 0, range: 1, fov: 0, updateRate: 100, noise: 0.01, failureProb: 0, name: 'Front-Right Line' }
    ]
  },
  {
    id: 'robot_swift',
    name: 'Wasp Interceptor Z',
    width: 9.5,
    length: 9.5,
    weight: 380, // lightweight speedster
    cgOffset: 1.0, // front bias
    wheelDiameter: 2.8,
    wheelPosition: 0.5,
    maxSpeed: 110, // ultra high speed
    acceleration: 240,
    deceleration: 320,
    motorTorque: 1.1,
    trackWidth: 8.5,
    batteryVoltage: 7.4,
    batteryCapacity: 280,
    internalResistance: 0.18,
    aiCode: getDefaultAiCode(),
    sensors: [
      { id: 'tof_f', type: 'tof', x: 0, y: 4.5, rotation: 0, range: 140, fov: 25, updateRate: 100, noise: 0.02, failureProb: 0.01, name: 'Long Range TOF' },
      { id: 'edge_fl', type: 'edge', x: -4.0, y: 4.2, rotation: 0, range: 1, fov: 0, updateRate: 120, noise: 0.02, failureProb: 0, name: 'FL Edge' },
      { id: 'edge_fr', type: 'edge', x: 4.0, y: 4.2, rotation: 0, range: 1, fov: 0, updateRate: 120, noise: 0.02, failureProb: 0, name: 'FR Edge' },
      { id: 'edge_rl', type: 'edge', x: -4.0, y: -4.2, rotation: 180, range: 1, fov: 0, updateRate: 120, noise: 0.02, failureProb: 0, name: 'RL Edge' },
      { id: 'edge_rr', type: 'edge', x: 4.0, y: -4.2, rotation: 180, range: 1, fov: 0, updateRate: 120, noise: 0.02, failureProb: 0, name: 'RR Edge' }
    ]
  }
];

export const EDUCATION_ARTICLES = [
  {
    title: 'How Mini Sumo Physics Work',
    cat: 'Physics',
    text: 'Mini Sumo is a highly tactical category defined by strict size (10x10cm) and weight (500g) rules. Our motor model maps motor power percentage to wheel target velocity scaled by instantaneous battery voltage. Acceleration curves model motor torque; if torque exceeds local friction parameters, wheels slip. Pushing power is a combination of mass, friction on tires, and motor current limit.'
  },
  {
    title: 'Configuring Sensor Pipelines Safely',
    cat: 'Hardware',
    text: 'TOF (Time of Flight) sensors shoot pin-point laser beams. They offer near-perfect precision but very narrow FOV. If an opponent is actively moving fast, TOF might fail to sweep them. Sonars emit wide acoustic cones (30°). They capture rapid angles easily, but surface deflection creates high distance variance. Placing edge IR sensors at the extreme corners ensures you capture white lines before drifting off.'
  },
  {
    title: 'Writing Advanced State Machines',
    cat: 'Software',
    text: 'The best competitive strategies do not just drive towards targets. They implement multiple layered states: SEARCH (with dynamic orbits to cover surface area), ATTACK_CHARGE, ATTACK_RAM (when close, apply maximum voltage), and EDGE_ESCAPE (which handles high-speed reactive baking, pivoting away from the line before re-initiating search loops).'
  }
];
