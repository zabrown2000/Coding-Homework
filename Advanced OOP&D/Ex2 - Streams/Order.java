//package Week05Generics.Ex05IBLSkeleton;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import static java.lang.Long.parseLong;

public class Order {

    private long orderId;
    private Date orderDate;
    private Date deliveryDate;
    private OrderStatus status;
    private long customerId;

    public Order(String orderInfo) {
        String[] subs = orderInfo.split(" ");

        long Oid = parseLong(subs[1]);
        Date OorderDate = null;
        Date OdeliveryDate = null;
        try {
            OorderDate = new SimpleDateFormat("dd/MM/yyyy").parse(subs[4]);
            OdeliveryDate = new SimpleDateFormat("dd/MM/yyyy").parse(subs[7]);
        } catch (ParseException e) {
            e.printStackTrace();
        }

        OrderStatus Ostatus = OrderStatus.valueOf(subs[9]);
        long OcustomerId = parseLong(subs[12]);

        setOrderId(Oid);
        setOrderDate(OorderDate);
        setDeliveryDate(OdeliveryDate);
        setStatus(Ostatus);
        setCustomerId(OcustomerId);
    }

    public Order(long Oid, Date OorderDate, Date OdeliveryDate, OrderStatus Ostatus, long OcustomerId) {
        setOrderId(Oid);
        setOrderDate(OorderDate);
        setDeliveryDate(OdeliveryDate);
        setStatus(Ostatus);
        setCustomerId(OcustomerId);
    }

    public String toString() {
        SimpleDateFormat ft = new SimpleDateFormat("dd/MM/yyyy"); //need this to make the date be the Israel way and not the default date format, MM/DD/YYYY
        return "order: " + getOrderId() + " order date: " + ft.format(getOrderDate()) + " delivery date: "
                + ft.format(getDeliveryDate()) + " status: " + getStatus() + " customr id: " + getCustomerId() + "\n";
    }

    public long getOrderId() {
        return orderId;
    }

    public void setOrderId(long orderId) {
        this.orderId = orderId;
    }

    public Date getOrderDate() {
        return orderDate;
    }

    public void setOrderDate(Date orderDate) {
        this.orderDate = orderDate;
    }

    public Date getDeliveryDate() {
        return deliveryDate;
    }

    public void setDeliveryDate(Date deliveryDate) {
        this.deliveryDate = deliveryDate;
    }

    public OrderStatus getStatus() {
        return status;
    }

    public void setStatus(OrderStatus status) {
        this.status = status;
    }

    public long getCustomerId() {
        return customerId;
    }

    public void setCustomerId(long customerId) {
        this.customerId = customerId;
    }
}