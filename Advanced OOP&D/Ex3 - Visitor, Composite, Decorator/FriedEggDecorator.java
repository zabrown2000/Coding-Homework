public class FriedEggDecorator extends ToppingDecorator {
    public FriedEggDecorator(Hamburger newHamburger) {
        super(newHamburger);
    }

    public String serve()
    {
        return this.hamburger.serve() + " with fried egg";
    }
}

