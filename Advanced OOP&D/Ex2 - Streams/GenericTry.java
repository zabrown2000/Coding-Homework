package Week05Generics.Ex05IBLSkeleton;

import java.util.ArrayList;
import java.util.List;

public class GenericTry <T>{
    public static <T> T returnType(T argument) { return argument; }

    public static void main(String[] args) {
        Integer inferredInteger = returnType(1);
        String inferredString = returnType("String");
        System.out.println(inferredInteger+" "+inferredString);
        List<String> list = new ArrayList();
//        list.add(1);
        Object o = list.get(0);
        String str = (String) o;

    }
}
