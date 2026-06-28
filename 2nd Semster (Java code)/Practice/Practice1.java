
class Main {
    public static void main(String[] args) {
        //System.out.println("Try programiz.pro");
        
        HourlyEmployee h1 = new  HourlyEmployee("Ahnaf","Sahaf",3315672, 100000);
        h1.print();
        SalariedEmployee s1 = new  SalariedEmployee("Jani","Na",5562414, 600000);
        s1.print();
        
    }
}

class Employee {

    private String firstname, lastname;
    int SSN;

    public Employee(String firstname, String lastname, int SSN) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.SSN = SSN;
    }

    public String getFirstname() {
        return firstname;
    }

    public String getLastname() {
        return lastname;
    }

    public int getSSN() {
        return SSN;
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public void setSSN(int SSN) {
        this.SSN = SSN;
    }

    public void print() {
        System.out.println("Hi! " + this.firstname + " " + this.lastname + ".\nYour SSN number is " + this.SSN);
    }

}

class HourlyEmployee extends Employee{
    private int salary;
    
    public HourlyEmployee(String firstname, String lastname, int SSN, int salary){
        super(firstname,lastname,SSN);
        this.salary = salary;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }
    
    public void computeGrossPay(){
    
    }
    public void computeNetPay(){
    
    }
    public void print() {
        super.print();
        System.out.println("Hourly Salary: " + this.salary);
    }
}
class SalariedEmployee extends Employee{
    private int salary;
    
    public SalariedEmployee(String firstname, String lastname, int SSN, int salary){
        super(firstname,lastname,SSN);
        this.salary = salary;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }
    
    public void computeGrossPay(){
    
    }
    public void computeNetPay(){
    
    }
    public void print() {
        super.print();
        System.out.println("Salaried Salary: " + this.salary);
    }
}
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    

