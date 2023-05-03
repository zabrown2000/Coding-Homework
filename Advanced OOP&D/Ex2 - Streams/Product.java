//package Week05Generics.Ex05IBLSkeleton;

import static java.lang.Long.parseLong;

public class Product {
    private long ProductId;
    private String name;
    private ProductCategory category;
    private double price;

    public Product(String orderInfo) {
        String[] subs = orderInfo.split(" ");

        long PId = parseLong(subs[1]);
        String Pname = subs[2];
        ProductCategory Pcategory = ProductCategory.valueOf(subs[4]);
        double Pprice = Double.valueOf(subs[6]);

        setProductId(PId);
        setName(Pname);
        setCategory(Pcategory);
        setPrice(Pprice);
    }

    public Product(long PId, String Pname, ProductCategory Pcategory, double Pprice) {
        setProductId(PId);
        setName(Pname);
        setCategory(Pcategory);
        setPrice(Pprice);

    }

    public String toString() {
        return "Product: " + getProductId() + " " + getName() + " category: " + getCategory() + " price: " + getPrice()
                + "\n";
    }

    public long getProductId() {
        return ProductId;
    }

    public void setProductId(long productId) {
        ProductId = productId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public ProductCategory getCategory() {
        return category;
    }

    public void setCategory(ProductCategory category) {
        this.category = category;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

}
