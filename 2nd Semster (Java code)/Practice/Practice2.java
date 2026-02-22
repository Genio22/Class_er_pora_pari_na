class Vehicle{
    private String name; 
    protected float speed;
    Vehicle(String name, float speed){
        this.name = name;
        speed = speed;
    }
    public void move(float distance){
        
    }
    public String getName(){
        return this.name;
    }
    public String describe(){
        return "Mr/Ms." + this.name + ". You are runing a at " + speed + ".";
    }
}

public class Main {
    
    public static void main(String[] args) {
        //System.out.println("Hello, World!");
        //System.out.println();
        Car c1 = new Car("BMW", 5);
        System.out.println(c1.describe());

        Airplane a1 = new Airplane("Boeing 747", 68.5f, 416);
        System.out.println(a1.describe());
    }
    
}
class Vehicle{
    private String name; 
    protected float speed = 45;
    Vehicle(String name){
        this.name = name;
    }
    public void move(float distance){
        
    }
    public String getName(){
        return this.name;
    }
    public String describe(){
        return this.name + ", with a top speed of " + speed + ".";
    }
}

class MotorVehicle extends Vehicle{
    protected int number_of_wheels; 
    protected float engine_volume;
    protected MotorVehicle(String name){
        super(name);
    }
    public String describe(){
        String b = super.describe();
        return b + "\nCar is powered with a " + engine_volume + " v" + (int)engine_volume +" engine";
    }
    public String honk_horn(){
        return "Fuck U";
    }
}

class Truck extends MotorVehicle{
    private float horsepower;
    public Truck(String name,float horsepower){
        super(name);
        this.horsepower = horsepower;
    }
    public String describe(){
        String c = super.describe();
        return c + "with total" + this.horsepower + " make the a beast.";
    }
    public String honk_horn(){
        return "Fuck U";
    }
}

class Car extends MotorVehicle{
    private int num_doors;
    public Car(String name, int num_doors){
        super (name);
        this.num_doors = num_doors;
    }
    public String describe(){
        String d = super.describe();
        return d + "\nCar feature " + num_doors + " doors for easy acces.";
    }
    public String honk_horn(){
        return "Fuck U";
    }
}
class Airplane extends Vehicle{
    private float wingspan;
    private int capacity;
    public Airplane(String name, float wingspan,int capacity){
        super(name);
        this.wingspan = wingspan;
        this.capacity = capacity;
        this.speed = 900;
    }
    private void landing_gear(boolean set){
        
    }
    public void move(float distance){
        float time = distance / speed;
        System.out.println(getName() + " will take " + time + " hours to fly " + distance + " km.");
    }
    public String describe(){
        return getName() + " is an airplane with a wingspan of " + wingspan +
               " meters and capacity of " + capacity + " passengers, flying at " + speed + " km/h.";
    }
}













