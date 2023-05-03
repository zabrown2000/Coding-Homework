//package Week05Generics.Ex05IBLSkeleton;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.stream.Collectors;

public class DataSource {

    public static List<Customer> allCustomers;
    public static List<Order> allOrders;
    public static List<Product> allProducts;
    public static List<OrderProduct> allOrderProducts;
    // Update this path according to your data files location
    public static String basePath = ""; //"data/Ex05IBL/";
    public static String customersPath = basePath + "customers.txt";
    public static String ordersPath = basePath + "orders.txt";
    public static String productsPath = basePath + "products.txt";
    public static String orderProductPath = basePath + "orderProduct.txt";

    static {
        try {
            allCustomers = readCustomersfromFile();
            allOrders = readOrdersfromFile();
            allProducts = readProductsfromFile();
            allOrderProducts = readOrderProductsfromFile();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Read customers from customersPath using streams and return a list of customers
     * @return List of customers
     * @throws IOException if an I/O error occurs opening the file
     */
    public static List<Customer> readCustomersfromFile() throws IOException {
        return Files.lines(Paths.get(customersPath))
                .map(customer -> new Customer(customer)) //each line from the file is made into a new customer
                .collect(Collectors.toList());
    }

    /**
     * Read orders from ordersPath using streams and return a list of orders
     * @return List of orders
     * @throws IOException if an I/O error occurs opening the file
     */
    public static List<Order> readOrdersfromFile() throws IOException {
        return Files.lines(Paths.get(ordersPath))
                .map(order -> new Order(order))//each line from the file is made into a new order
                .collect(Collectors.toList());
    }

    /**
     * Read products from productsPath using streams and return a list of products
     * @return List of products
     * @throws IOException if an I/O error occurs opening the file
     */
    public static List<Product> readProductsfromFile() throws IOException {
        return Files.lines(Paths.get(productsPath))
                .map(product -> new Product(product))//each line from the file is made into a new product
                .collect(Collectors.toList());
    }

    /**
     * Read orderProducts from orderProductPath using streams and return a list of orderProducts
     * @return List of orderProducts
     * @throws IOException if an I/O error occurs opening the file
     */
    public static List<OrderProduct> readOrderProductsfromFile() throws IOException {
        return Files.lines(Paths.get(orderProductPath))
                .map(orderProduct -> new OrderProduct(orderProduct)) //each line from the file is made into a new orderProduct
                .collect(Collectors.toList());
    }
}
