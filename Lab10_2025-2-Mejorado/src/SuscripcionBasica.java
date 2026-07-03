public class SuscripcionBasica extends Suscripcion{
    public String getTipo(){
        return "BASICA";
    }

    public double calcularPrecio(){
        return 50.00;
    }
}
