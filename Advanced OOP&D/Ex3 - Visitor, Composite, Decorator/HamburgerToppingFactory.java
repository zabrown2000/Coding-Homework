public class HamburgerToppingFactory {
    public static Hamburger addTopping(Hamburger hamburger, String topping) {
        switch (topping) {
            case "ch":
                return new ChipsDecorator(hamburger);
            case "or":
                return new OnionRingsDecorator(hamburger);
            case "sa":
                return new SaladDecorator(hamburger);
            case "fe":
                return new FriedEggDecorator(hamburger);
            default:
                return hamburger;
        }
    }
}
