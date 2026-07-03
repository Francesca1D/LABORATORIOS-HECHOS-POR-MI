public class SuscripcionPremium extends Suscripcion{
    public String getTipo(){
        return "PREMIUM";
    }

    public double calcularPrecio(){
        return 80.00;
    }

}
