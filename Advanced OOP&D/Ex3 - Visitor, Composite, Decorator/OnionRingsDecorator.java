public class OnionRingsDecorator extends ToppingDecorator {
    public OnionRingsDecorator(Hamburger newHamburger) {
        super(newHamburger);
    }

    public String serve()
    {
        return this.hamburger.serve() + " with onion rings";
    }
}

