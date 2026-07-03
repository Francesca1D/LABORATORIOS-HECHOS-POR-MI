import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Restaurante {
    private ArrayList<DetalleComanda> lcomanda;
    private Scanner arch;

    public Restaurante(String nombre) throws FileNotFoundException{
        arch = new Scanner(new File(nombre));
        lcomanda = new ArrayList<>();

    }

    public void carga(){
        while(arch.hasNext()){
            DetalleComanda aux= new DetalleComanda();
            aux.leecomanda(arch);
            lcomanda.add(aux);
        }
    }
    public void muestra(){
        for(DetalleComanda aux: lcomanda){
            aux.imprimecomanda();
            System.out.println();
        }
    }
}
