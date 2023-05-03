public class SaladDecorator extends ToppingDecorator {
    public SaladDecorator(Hamburger newHamburger) {
        super(newHamburger);
    }

    public String serve()
    {
        return this.hamburger.serve() + " with salad";
    }
}

