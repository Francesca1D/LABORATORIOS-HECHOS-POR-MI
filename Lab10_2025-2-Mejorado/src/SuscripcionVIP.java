public class SuscripcionVIP extends Suscripcion{
    public String getTipo(){
        return "VIP";
    }

    public double calcularPrecio(){
        return 100.00;
    }
}
