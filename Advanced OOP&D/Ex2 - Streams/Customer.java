//package Week05Generics.Ex05IBLSkeleton;

import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

public class Customer {
    private long id;
    private String name;
    private int tier;

    public Customer(String customerInfo) {
        String[] subs = customerInfo.split(" ");
        long Cid = parseLong(subs[1]);
        String Cname = subs[3];
        int Ctier = parseInt(subs[5]);

        setCustomerId(Cid);
        setName(Cname);
        setTier(Ctier);
    }

    public Customer(long Cid, String Cname, int Ctier) {
        setCustomerId(Cid);
        setName(Cname);
        setTier(Ctier);
    }

    public String toString() {
        return "customer: " + getCustomerId() + " name: " + getName() + " tier: " + getTier() + "\n";
    }

    public long getCustomerId() {
        return id;
    }

    public void setCustomerId(long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getTier() {
        return tier;
    }

    public void setTier(int tier) {
        this.tier = tier;
    }
}