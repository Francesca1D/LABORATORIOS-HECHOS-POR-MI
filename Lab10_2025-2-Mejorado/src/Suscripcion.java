import java.util.List;
import java.util.Scanner;

public abstract class Suscripcion extends Registro{
    private int idUsuario;
    private int idCanal;
    private Usuario usuario;
    private CanalStreaming canal;

    public int getIdCanal() {
        return idCanal;
    }

    public void setIdCanal(int idCanal) {
        this.idCanal = idCanal;
    }

    public int getIdUsuario() {
        return idUsuario;
    }

    public void setIdUsuario(int idUsuario) {
        this.idUsuario = idUsuario;
    }
    //    BASICA 1 1
    //    PREMIUM 1 4
    //    VIP 1 7
    @Override
    public boolean leer(Scanner arch){
        if(arch.hasNext()){
            idUsuario = arch.nextInt();
            idCanal = arch.nextInt();
            return true;
        }
        return false;
    }

    @Override
    public void imprimir(){
        System.out.printf("      -%-10s | Usuario: ", getTipo());
        System.out.printf("%-4d",idUsuario);
        System.out.printf("%-20s",usuario.getNombreCompleto());

        System.out.printf(" | Canal: %-4d",idCanal);
        System.out.printf("%-20s",canal.getNombre());
        System.out.printf(" | Precio: %3.2f",calcularPrecio());


    }

    public abstract String getTipo();
    public abstract double calcularPrecio();

    public void agregarUsuario( Usuario auxUsu){
        usuario = auxUsu;
    }

    public void agregarCanal(CanalStreaming auxCan){
        canal = auxCan;
    }

}
