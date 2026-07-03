public class Alumno extends Persona {
    private int codigo;
    private double craest;
    private String correo;

    public Alumno(){
        this.codigo=0;
        this.craest=0;

    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public double getCraest() {
        return craest;
    }

    public void setCraest(double craest) {
        this.craest = craest;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }
}
