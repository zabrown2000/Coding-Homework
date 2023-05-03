//package Week05Generics.Ex05IBLSkeleton;

import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

import static java.util.Collections.reverseOrder;
import static java.util.Map.Entry.comparingByValue;
import static java.util.function.UnaryOperator.identity;

import java.util.Collections;

public class BL implements IBL {

    /**
     * Returns a product with the given id
     * 
     * @param productId the id of the product
     * @return the product with the given id
     * @throws IllegalArgumentException if there is no product with the given id
     */
    @Override
    public Product getProductById(long productId) {
        return DataSource.allProducts.stream()
                .filter(product -> product.getProductId() == productId)
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("No product with id " + productId));
    }

    /**
     * Returns an order with the given id
     * 
     * @param orderId the id of the order
     * @return the order with the given id
     * @throws IllegalArgumentException if there is no order with the given id
     */
    @Override
    public Order getOrderById(long orderId) {
        return DataSource.allOrders.stream()
                .filter(order -> order.getOrderId() == orderId)
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("No order with id " + orderId));
    }

    /**
     * Returns a customer with the given id
     * 
     * @param customerId the id of the customer
     * @return the customer with the given id
     */
    @Override
    public Customer getCustomerById(long customerId) {
        return DataSource.allCustomers.stream()
                .filter(customer -> customer.getCustomerId() == customerId)
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("No customer with id " + customerId));
    }

    /**
     * Returns the list of products that belong to category cat with price equal or
     * smaller than price.
     * The list should be sorted by the product ID.
     * 
     * @param cat   the category of the product
     * @param price the price of the product to be equal or smaller than
     * @return the list of products
     */
    @Override
    public List<Product> getProducts(ProductCategory cat, double price) {
        return DataSource.allProducts.stream()
                .filter(product -> product.getCategory() == cat)
                .filter(product -> product.getPrice() <= price)
                .sorted(Comparator.comparing(Product::getProductId))
                .collect(Collectors.toList());
    }

    /**
     * Returns the list of popular customers. A customer is popular if
     * it belongs to tier 3 and it has more than 10 orders.
     * The list should be sorted by the customer ID.
     * 
     * @return the list of popular customers
     */
    @Override
    public List<Customer> popularCustomers() {
        return DataSource.allCustomers.stream()
                .filter(customer -> customer.getTier() == 3)
                .filter(customer -> getCustomerOrders(customer.getCustomerId()).size() > 10)
                .sorted(Comparator.comparing(Customer::getCustomerId))
                .collect(Collectors.toList());
    }

    /**
     * Returns the list of orders of the given customer.
     * The list should be sorted by the order ID.
     * 
     * @param customerId the id of the customer
     * @return the list of orders of the given customer
     */
    @Override
    public List<Order> getCustomerOrders(long customerId) {
        return DataSource.allOrders.stream()
                .filter(order -> order.getCustomerId() == customerId)
                .sorted(Comparator.comparing(Order::getOrderId))
                .collect(Collectors.toList());
    }

    /**
     * Returns the number of unique products in the given order.
     * 
     * @param orderId the id of the order
     * @return the number of unique products in the given order
     */
    @Override
    public long numberOfProductInOrder(long orderId) {
        return getOrderProducts(orderId).stream()
                .map(Product::getProductId)
                .distinct()
                .count();
    }

    /**
     * Returns the list of products that have been ordered at least orderedQuantity
     * times.
     * The list should be sorted by the product ID.
     * 
     * @param orderedQuantity the number of times that a product has been ordered
     * @return the list of products
     */
    @Override
    public List<Product> getPopularOrderedProduct(int orderedQuantity) {
        Map<Long, Integer> newMap =  DataSource.allOrderProducts.stream() //getting map of the product ids with the total quantity of each
                .collect(Collectors.groupingBy(OrderProduct::getProductId, Collectors.summingInt(OrderProduct::getQuantity)));

        return newMap.entrySet().stream() //getting key-value pairs from map
                .filter(entry -> entry.getValue() >= orderedQuantity)//getting rid of entries with quantity below minimum
                .map(entry -> getProductById(entry.getKey())) //now getting product for each product id
                .sorted(Comparator.comparing(Product::getProductId)) //sorting by product id
                .collect(Collectors.toList());
    }

    /**
     * Returns the list of products that have been ordered in the given order.
     * The list should be sorted by the product ID.
     * 
     * @param orderId the id of the order
     * @return the list of products
     */
    @Override
    public List<Product> getOrderProducts(long orderId) {
        return DataSource.allOrderProducts.stream()
                .filter(orderProduct -> orderProduct.getOrderId() == orderId)
                .map(OrderProduct::getProductId)
                .distinct()
                .map(this::getProductById)
                .sorted(Comparator.comparing(Product::getProductId))
                .collect(Collectors.toList());
    }

    /**
     * Returns the list of customers that have ordered the given product.
     * The list should be sorted by the customer ID.
     * 
     * @param productId the id of the product
     * @return the list of customers
     */
    @Override
    public List<Customer> getCustomersWhoOrderedProduct(long productId) {
        return DataSource.allOrderProducts.stream()
                .filter(orderProduct -> orderProduct.getProductId() == productId)
                .map(OrderProduct::getOrderId) // get the order id of each order product
                .distinct() // make sure that each order id is unique
                .map(this::getOrderById) // get the order for each order id
                .map(Order::getCustomerId) // get the customer id of each order
                .distinct() // make sure that each customer id is unique
                .map(this::getCustomerById) // get the customer for each customer id
                .sorted(Comparator.comparing(Customer::getCustomerId))
                .collect(Collectors.toList());
    }

    /**
     * Returns the product that has been ordered the most times, disregarding the
     * quantity.
     * 
     * @return the product that has been ordered the most or null if there are no
     *         products ordered
     */
    @Override
    public Product getMaxOrderedProduct() {
        return DataSource.allOrderProducts.stream()
                // group order products by product id and count the number of each
                // we get a map where the key is the product id and the value is the number of
                // times it has been ordered
                .collect(Collectors.groupingBy(OrderProduct::getProductId, Collectors.counting()))
                .entrySet().stream() // convert the map to a stream of map entries (key-value pairs)
                .max(Comparator.comparing(Map.Entry::getValue)) // get the entry with the highest value
                .map(Map.Entry::getKey) // get the key (product id) of the entry
                .map(this::getProductById)
                .orElse(null);
    }

    /**
     * Returns the total cost of a given order
     * 
     * @param orderID the id of the order
     * @return the total cost of the order
     */
    @Override
    public double sumOfOrder(long orderID) {
        return DataSource.allOrderProducts.stream()
                .filter(orderProduct -> orderProduct.getOrderId() == orderID)
                // map each order product to the cost of the product times the quantity
                .mapToDouble(orderProduct -> {
                    long productId = orderProduct.getProductId();
                    Product product = getProductById(productId);
                    return product.getPrice() * orderProduct.getQuantity();
                })
                .sum(); // sum the costs of all the products in the order
    }

    /**
     * Returns the list of orders that have a total cost larger than price.
     * The list should be sorted by the order ID.
     * 
     * @param price the price of the order to be larger than
     * @return the list of orders
     */
    @Override
    public List<Order> getExpensiveOrders(double price) {
        return DataSource.allOrders.stream()
                .filter(order -> sumOfOrder(order.getOrderId()) > price)
                .sorted(Comparator.comparing(Order::getOrderId))
                .collect(Collectors.toList());
    }

    /**
     * Returns the number of orders for a given customer.
     * 
     * @param customer the customer
     * @return the number of orders for the customer
     */
    public long numberOfOrders(Customer customer) {
        return DataSource.allOrders.stream()
                .filter(order -> order.getCustomerId() == customer.getCustomerId())
                .count();
    }

    /**
     * Returns the list of tier 3 customers who have the maximal number of orders.
     * The list should be sorted by the customer ID.
     * 
     * @return the list of tier 3 customers who have the maximal number of orders
     */
    @Override
    public List<Customer> ThreeTierCustomerWithMaxOrders() {
        List<Customer> sortedCustomers = DataSource.allCustomers.stream()
                .filter(customer -> customer.getTier() == 3)
                // map each customer id to the number of orders for that customer
                .collect(Collectors.toMap(Customer::getCustomerId, this::numberOfOrders))
                .entrySet().stream() // convert the map to a stream of map entries (key-value pairs)
                // sort by number of orders in descending order
                .sorted(Comparator.comparing(Map.Entry::getValue, Comparator.reverseOrder()))
                .map(entry -> getCustomerById(entry.getKey())) // map customer id to customer
                .collect(Collectors.toList());
        // get the three customers with the highest number of orders
        int maxOrders = sortedCustomers.size() > 3 ? 3 : sortedCustomers.size();
        return sortedCustomers.subList(0, maxOrders);
    }

}
