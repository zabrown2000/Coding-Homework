package Week05Generics.Ex05IBLSkeleton;

class Program
{
    public static void main(String args[]) {

        IBL myBl = new BL();

        System.out.println("---------getProductById:--------");
        System.out.println(myBl.getProductById(495L));

        System.out.println("---------getOrderById:--------");
        System.out.println(myBl.getOrderById(241L));

        System.out.println("---------getCustomerById:--------");
        System.out.println(myBl.getCustomerById(284L));

        System.out.println("---------getProducts:--------");
        myBl.getProducts(ProductCategory.Accessories, 50.0).forEach(System.out::print);

        System.out.println("---------popularCustomers:--------");
        myBl.popularCustomers().forEach(System.out::print);

        System.out.println("---------getCustomerOrders:--------");
        myBl.getCustomerOrders(83L).forEach(System.out::print);

        System.out.println("---------numberOfProductInOrder:--------");
        System.out.println(myBl.numberOfProductInOrder(76L));

        System.out.println("---------getPopularOrderedProduct:--------");
        myBl.getPopularOrderedProduct(55).forEach(System.out::print);

        System.out.println("---------getOrderProducts:--------");
        myBl.getOrderProducts(24L).forEach(System.out::print);

        System.out.println("---------getCustomersWhoOrderedProduct:--------");
        myBl.getCustomersWhoOrderedProduct (18L).forEach(System.out::print);

        System.out.println("---------getMaxOrderedProduct:--------");
        myBl.getMaxOrderedProduct();
        System.out.println(myBl.getMaxOrderedProduct());

        System.out.println("---------sumOfOrder:--------");
        System.out.println(myBl.sumOfOrder(24L));

        System.out.println("---------getExpensiveOrders:--------");
        myBl.getExpensiveOrders(2200).forEach(System.out::print);

        System.out.println("---------ThreeTierCustomerWithMaxOrders:--------");
        myBl.ThreeTierCustomerWithMaxOrders().forEach(System.out::print);

    }
} 