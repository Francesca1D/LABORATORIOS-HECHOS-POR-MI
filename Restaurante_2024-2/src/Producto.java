import java.util.Scanner;

public abstract class Producto {
    private String nombre;
    private double precio;

    public Producto(){
        precio=0;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    //142 B Cafe 2 grande
    //142 B Agua_Mineral 2.5 pequeno
    //142 E Quesadillas 5.5 sin_picante

    public abstract String tiposoy();

    public void lee(Scanner arch){
        nombre = arch.next();
        precio = arch.nextDouble();
    }

    public void imprime(){
        System.out.println("Nombre: " + nombre);
        System.out.println("Precio: " + precio);
    }
}
