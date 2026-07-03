import java.util.Scanner;

public class CanalStreaming extends Registro{
    private int id;
    private String nombre;
    private String descripcion;
    private String fechaCreacion;
    private long cantVisualizaciones;
    private String categoria;

    public CanalStreaming(){
        id=0;
        cantVisualizaciones=0;
    }

    public long getCantVisualizaciones() {
        return cantVisualizaciones;
    }

    public void setCantVisualizaciones(long cantVisualizaciones) {
        this.cantVisualizaciones = cantVisualizaciones;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public String getFechaCreacion() {
        return fechaCreacion;
    }

    public void setFechaCreacion(String fechaCreacion) {
        this.fechaCreacion = fechaCreacion;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
//    private int id;
//    private String nombre;
//    private double descripcion;
//    private String fechaCreacion;
//    private long cantVisualizaciones;
//    private String categoria;

    //9 AutoTech Autos_y_tecnologia 2022-03-05 35000 Tecnologia
//10 FashionStyle Moda_y_tendencias 2021-04-22 68000 Moda
//            FIN
    @Override
    public boolean leer(Scanner arch){
        if(!arch.hasNextInt()){
            arch.next(); //FIN
            return false;
        }
        id = arch.nextInt();
        nombre = arch.next();
        descripcion = arch.next();
        fechaCreacion = arch.next();
        cantVisualizaciones = arch.nextLong();
        categoria = arch.next();

        return true;
    }

    @Override
    public void imprimir(){

    }

}
