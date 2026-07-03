import java.util.Scanner;

public abstract class Suscripcion extends Registro {
    private int idUsuario;
    private int idCanal;
    private Usuario usuario;
    private CanalStreaming canal;

    public Suscripcion(){
        idUsuario=0;
        idCanal=0;
    }

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

    public void agregarUsuario(Usuario auxUsu){
        usuario = auxUsu;
    }

    public void agregarCanal(CanalStreaming auxCan){
        canal = auxCan;
    }

//    BASICA 1 1
//    PREMIUM 1 4
//    VIP 1 7
//    private int idUsuario;
//    private int idCanal;
//    private Usuario usuario;
//    private CanalStreaming canal;



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
//        System.out.println("         -" + getTipo() + "| Usuario: " + idUsuario + "  " + usuario.getNombreCompleto());
    System.out.printf("%-5s %1s %-15s %1s %-8s %2d %-20s %1s %-6s %d    %-20s %s %-7s %3.2f\n"," ","-",getTipo(), "|","Usuario:",idUsuario,
            usuario.getNombreCompleto(), "|","Canal:",idCanal, canal.getNombre(),"|","Precio:", calcularPrecio());

    }

    public abstract String getTipo();

    public abstract double calcularPrecio();

}
