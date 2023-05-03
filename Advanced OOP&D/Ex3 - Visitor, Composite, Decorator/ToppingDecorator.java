public abstract class ToppingDecorator implements Hamburger {
    protected Hamburger hamburger;

    public ToppingDecorator(Hamburger newHamburger) {
        this.hamburger = newHamburger;
    }

}
