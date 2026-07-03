import java.util.Scanner;

public class DetalleComanda {
    private int id;
    private Producto pedido;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
//142 B Cafe 2 grande
//142 B Agua_Mineral 2.5 pequeno
//142 E Quesadillas 5.5 sin_picante
    public void  leecomanda(Scanner arch){
        String tipo;
        id=arch.nextInt();
        tipo= arch.next();
        if(tipo.compareTo("B")==0)
            pedido = new Bebida();
        else
            if(tipo.compareTo("E")==0)
                pedido = new Entrada();
            else
                pedido = new PlatoFondo();

        pedido.lee(arch);
    }

    public void imprimecomanda(){
        System.out.println("Id: "+id);
        pedido.imprime();
        System.out.println("Tipo: "+pedido.tiposoy());
    }

}
