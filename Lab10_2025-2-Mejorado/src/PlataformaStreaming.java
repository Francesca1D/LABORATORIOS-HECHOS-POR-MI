import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class PlataformaStreaming {
    private ArrayList<CanalStreaming> canales;
    private ArrayList<Usuario> usuarios;
    private ArrayList<Suscripcion>suscripciones;
    private Scanner arch;

    public PlataformaStreaming(String nombre)throws FileNotFoundException {
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

    public void imprimirReporte(){
        System.out.println("========================================================================================================================");
        System.out.printf("%-50s %20s\n"," ","REPORTE DE USUARIOS");
        System.out.println("========================================================================================================================");
        System.out.printf("%-4s","ID");
        System.out.printf("%-20s","Nombre Completo");
        System.out.printf("%-10s","DNI");
        System.out.printf("%-5s","Edad");
        System.out.printf("%-10s","Ciudad");
        System.out.printf("%-12s","F. Nac");
        System.out.printf("%-12s","Telefono");
        System.out.printf("%-25s","Email");
        System.out.printf("%-20s","Ocupacion");
        System.out.println();
        System.out.println("------------------------------------------------------------------------------------------------------------------------");
        for(Usuario aux : usuarios){
            aux.imprimir();
            System.out.println();
        }

    }
//9 AutoTech Autos_y_tecnologia 2022-03-05 35000 Tecnologia
//10 FashionStyle Moda_y_tendencias 2021-04-22 68000 Moda
//            FIN
    private void cargarCanales(){
        while(true){
            CanalStreaming aux = new CanalStreaming();
            if(!aux.leer(arch)) break;
            canales.add(aux);
        }
    }

    private void cargarUsuarios(){
        while(true){
            Usuario aux = new Usuario();
            if(!aux.leer(arch)) break;
            usuarios.add(aux);
        }
    }
//    BASICA 1 1
//    PREMIUM 1 4
//    VIP 1 7
    private void cargarSuscripciones(){
        String tipo;
        while(arch.hasNext()){
            Suscripcion aux;
            tipo = arch.next();
            if(tipo.compareTo("BASICA")==0)
                aux = new SuscripcionBasica();
            else
                if(tipo.compareTo("PREMIUM")==0)
                    aux = new SuscripcionPremium();
                else
                    aux = new SuscripcionVIP();
            aux.leer(arch);

            Usuario auxUsu = buscarUsuario(aux.getIdUsuario());
            CanalStreaming auxCan = buscarCanal(aux.getIdCanal());
            aux.agregarUsuario(auxUsu);
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
}
