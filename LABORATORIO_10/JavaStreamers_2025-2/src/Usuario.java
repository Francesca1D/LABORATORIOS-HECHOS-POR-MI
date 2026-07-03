import java.util.ArrayList;
import java.util.Scanner;

public class Usuario extends Registro {
    private int id;
    private String nombreCompleto;
    private int dni;
    private int edad;
    private String ciudad;
    private String fechaNacimiento;
    private String telefono;
    private String email;
    private String ocupacion;
    private ArrayList<Suscripcion> suscripciones;

    public Usuario() {
        id=0;
        dni=0;
        edad=0;
        suscripciones = new ArrayList<>();

    }

    public String getCiudad() {
        return ciudad;
    }

    public void setCiudad(String ciudad) {
        this.ciudad = ciudad;
    }

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getFechaNacimiento() {
        return fechaNacimiento;
    }

    public void setFechaNacimiento(String fechaNacimiento) {
        this.fechaNacimiento = fechaNacimiento;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombreCompleto() {
        return nombreCompleto;
    }

    public void setNombreCompleto(String nombreCompleto) {
        this.nombreCompleto = nombreCompleto;
    }

    public String getOcupacion() {
        return ocupacion;
    }

    public void setOcupacion(String ocupacion) {
        this.ocupacion = ocupacion;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }
//    private int id;
//    private String nombreCompleto;
//    private int dni;
//    private int edad;
//    private String ciudad;
//    private String fechaNacimiento;
//    private String telefono;
//    private String email;
//    private String ocupacion;
//    private ArrayList<Suscripcion> suscripciones;

//19 Bianca_Mendoza 71025648 28 Lima 1997-06-14 999888777 bmendoza@gmail.com Chef
//20 Hector_Salinas 76541238 30 Arequipa 1995-04-28 934512789 hsalinas@gmail.com Programador
//    FIN

    @Override
    public boolean leer(Scanner arch){
        if(!arch.hasNextInt()) {
            arch.next(); //FIN
            return false;
        }
        id = arch.nextInt();
        nombreCompleto = arch.next();
        dni = arch.nextInt();
        edad = arch.nextInt();
        ciudad = arch.next();
        fechaNacimiento = arch.next();
        telefono = arch.next();
        email = arch.next();
        ocupacion = arch.next();

        return true;
    }

    public ArrayList<Suscripcion>getSuscripciones(){
        return suscripciones;
    }

    @Override
    public void imprimir(){
        System.out.printf("%2d   ",id);
        System.out.printf("%-17s",nombreCompleto);
        System.out.printf("%16d",dni);
        System.out.printf("%5d    ",edad);
        System.out.printf("%-10s",ciudad);
        System.out.printf("%-15s",fechaNacimiento);
        System.out.printf("%-10s ",telefono);
        System.out.printf("%-23s",email);
        System.out.printf("%-20s",ocupacion);
        System.out.println();
        System.out.printf("%5s %-20s\n",' ',"Suscripciones: ");
        for(Suscripcion aux: suscripciones){
            aux.imprimir();

//            System.out.println();
        }

    }

    public double calcularCosto(){
        double costo=0.00;
        for(Suscripcion sub: suscripciones){
            costo += sub.calcularPrecio();
        }
        return costo;
    }
}
