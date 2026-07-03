import java.io.IOException;

public class Poliplatos {
    public static void main(String[] args) throws IOException{
        Restaurante res= new Restaurante("comandas2.txt");
        res.carga();
        res.muestra();

    }
}
