package Week05Generics.Ex05IBLSkeleton;

import java.util.ArrayList;
import java.util.List;

public interface Consumer {
    public void consume(String parameter);

    public static void main(String[] args) {
        List list = new ArrayList();
        list.add("foo");
        Object o = list.get(0);
        String foo = (String) o;
        list.add(1);
        Object o1 = list.get(0);
        String foo1 = (String) o1;

    }
}
