import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class PlataformaStreaming {
    private ArrayList<CanalStreaming> canales;
    private ArrayList <Usuario> usuarios;
    private ArrayList<Suscripcion>suscripciones;
    private Scanner arch;

//    public void PlataformaStreaming(){
//
//    }

    public PlataformaStreaming(String nombre) throws FileNotFoundException{
        arch = new Scanner(new File(nombre));
        canales = new ArrayList<>();
        usuarios = new ArrayList<>();
        suscripciones = new ArrayList<>();
    }

    public void cargarDatos(){
        cargarCanales();
        cargarUsuarios();
        cargarSuscripciones();

    }

    public void cargarCanales(){
        while(true){
            CanalStreaming aux = new CanalStreaming();
            if(!aux.leer(arch)) break;
            canales.add(aux);
        }
    }
//    private ArrayList<Suscripcion> suscripciones;
    public void cargarUsuarios(){
        while(true){
            Usuario aux = new Usuario();
            if(!aux.leer(arch)) break;
            usuarios.add(aux);

        }
    }
//    BASICA 1 1
//    PREMIUM 1 4
//    VIP 1 7
    public void cargarSuscripciones(){
        while(arch.hasNext()){
            Suscripcion aux;
            String tipo = arch.next();
            if(tipo.compareTo("BASICA")==0)
                aux = new SuscripcionBasica();
            else
                if(tipo.compareTo("PREMIUM")==0)
                    aux = new SuscripcionPremium();
                else
                    aux = new SuscripcionVIP();

            aux.leer(arch);

            Usuario auxUsu = buscarUsuario(aux.getIdUsuario());
            aux.agregarUsuario(auxUsu);
            CanalStreaming auxCan = buscarCanal(aux.getIdCanal());
            aux.agregarCanal(auxCan);

            auxUsu.getSuscripciones().add(aux);

            suscripciones.add(aux);
        }
    }

    private Usuario buscarUsuario(int id){
        for(Usuario aux : usuarios){
            if(aux.getId()==id)
                return aux;
        }
        return null;
    }

    private CanalStreaming buscarCanal(int id){
        for(CanalStreaming aux : canales){
            if(aux.getId()==id)
                return aux;
        }
        return null;
    }

    public void imprimirReporte(){
        System.out.println("========================================================================================================================");
        System.out.println("                                                  REPORTE DE USUARIOS");
        System.out.println("========================================================================================================================");

        System.out.printf("%-4s %-23s %-10s %-5s %-12s %-12s %-10s %-20s %-20s\n","ID","Nombre Completo","DNI","Edad",
                "Ciudad", "F.Nac","Telefono", "Email", "Ocupacion");
        System.out.println("------------------------------------------------------------------------------------------------------------------------");
        for(Usuario aux:usuarios){
            aux.imprimir();
            System.out.println("      "+"Costo total: "+ aux.calcularCosto());
        }
    }

}
