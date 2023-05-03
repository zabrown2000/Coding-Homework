public class ChipsDecorator extends ToppingDecorator {
    public ChipsDecorator(Hamburger newHamburger) {
        super(newHamburger);
    }

    public String serve()
    {
        return this.hamburger.serve() + " with chips";
    }
}

