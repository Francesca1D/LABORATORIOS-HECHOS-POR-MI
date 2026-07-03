import java.util.Scanner;

public class PlatoFondo extends Producto{
    private int proteina;

    public PlatoFondo(){
        proteina=0;
    }

    public int getProteina() {
        return proteina;
    }

    public void setProteina(int proteina) {
        this.proteina = proteina;
    }

    //142 E Bruschetta 4 picante
    //142 P Pasta_Alfredo 10 4
    //142 P Pollo_a_la_Brasa 15 1
    @Override
    public String tiposoy(){
        return "Plato Fondo";
    }

    @Override
    public void lee(Scanner arch){
        super.lee(arch);
        proteina = arch.nextInt();

    }

    @Override
    public void imprime(){
        super.imprime();
        if(proteina==1)
            System.out.println("Pollo");
        if(proteina==2)
            System.out.println("Carne");
        if(proteina==3)
            System.out.println("Pescados");
        if(proteina==4)
            System.out.println("Lacteos");

    }

}
