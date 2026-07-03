import java.util.Scanner;

public class Entrada extends Producto{
    private boolean picante;

    public boolean isPicante() {
        return picante;
    }

    public void setPicante(boolean picante) {
        this.picante = picante;
    }

    //142 B Cafe 2 grande
    //142 B Agua_Mineral 2.5 pequeno
    //142 E Quesadillas 5.5 sin_picante

    @Override
    public String tiposoy(){
        return "E";
    }

    @Override
    public void lee(Scanner arch){
        String pica;
        super.lee(arch);
        pica = arch.next();
        if(pica.compareTo("picante")==0)
            picante=true;
    }

    @Override
    public void imprime(){
        super.imprime();
        if(picante)
            System.out.println("Picante");
        else
            System.out.println("Sin picante");

    }

}
