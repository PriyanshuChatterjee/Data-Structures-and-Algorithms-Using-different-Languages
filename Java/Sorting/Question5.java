class A{
    int x,y;

    A(){
        x = 10;
        y = 20;
    }

    void show(){
        System.out.println(x);
        System.out.println(y);
    }
}

public class Question5{
    
    public static void main(String[] args) {
        A o = new A();
        o.show();
    }
}