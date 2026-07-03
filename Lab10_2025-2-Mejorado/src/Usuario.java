import java.util.ArrayList;
import java.util.Scanner;

public class Usuario extends Registro{
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

    public Usuario(){
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

    public ArrayList<Suscripcion> getSuscripciones() {
        return suscripciones;
    }

//    19 Bianca_Mendoza 71025648 28 Lima 1997-06-14 999888777 bmendoza@gmail.com Chef
//20 Hector_Salinas 76541238 30 Arequipa 1995-04-28 934512789 hsalinas@gmail.com Programador
//    FIN

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

    @Override
    public boolean leer(Scanner arch){
        if(!arch.hasNextInt()){
            arch.next(); //FIN
            return false;
        }
        id= arch.nextInt();
        nombreCompleto = arch.next();
        dni = arch.nextInt();
        edad = arch.nextInt();
        ciudad = arch.next();
        fechaNacimiento = arch.next();
        telefono= arch.next();
        email = arch.next();
        ocupacion = arch.next();

        return true;
    }

    @Override
    public void imprimir(){
        System.out.printf("%-4d",id);
        System.out.printf("%-20s",nombreCompleto);
        System.out.printf("%-10d",dni);
        System.out.printf("%-4d",edad);
        System.out.printf("%-10s",ciudad);
        System.out.printf("%-12s",fechaNacimiento);
        System.out.printf("%-12s",telefono);
        System.out.printf("%-25s",email);
        System.out.printf("%-20s\n",ocupacion);
        for(Suscripcion aux : suscripciones){
            aux.imprimir();
            System.out.println();
        }
        System.out.printf("      Costo total : ");
        System.out.printf("%3.2f",calcularCosto());

    }

    public double calcularCosto(){
        double costo =0.00;
        for(Suscripcion sub: suscripciones){
            costo += sub.calcularPrecio();

        }
        return costo;
    }



}
