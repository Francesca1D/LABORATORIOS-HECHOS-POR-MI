import java.util.Scanner;

public class Bebida extends Producto{
    private String tamano;

    public String getTamano() {
        return tamano;
    }

    public void setTamano(String tamano) {
        this.tamano = tamano;
    }

    //142 B Cafe 2 grande
    //142 B Agua_Mineral 2.5 pequeno
    //142 E Quesadillas 5.5 sin_picante

    @Override
    public String tiposoy(){
        return "B";
    }

    @Override
    public void lee(Scanner arch){
        super.lee(arch);
        tamano = arch.next();

    }
    @Override
    public void imprime(){
        super.imprime();
        System.out.println("Tamano: " + tamano);

    }
}
