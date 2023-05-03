
public class HamburgerFactory {
    public static Hamburger createHamburger(String code){
        switch (code){
            case "classic":
                return new ClassicHamburger();
            case "hm":
                return new HomemadeHamburger();
            case "la":
                return new LambHamburger();
            case "sp":
                return new SpicyHamburger();
            default:
                throw new RuntimeException("wrong Hamburger");
        }

    }
}

