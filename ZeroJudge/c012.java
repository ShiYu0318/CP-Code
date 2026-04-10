import java.util.*;

public class c012
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine())
        {
            HashMap<Integer, Integer> map = new HashMap<>();            
            String s = sc.nextLine();
            for(char c : s.toCharArray()) map.merge((int)c, 1, Integer::sum);
            map.entrySet().stream()
            .sorted(Comparator.comparingInt(Map.Entry<Integer, Integer>::getValue)
            .thenComparing(Map.Entry.<Integer, Integer>comparingByKey(Comparator.reverseOrder())))
            .forEach(e -> System.out.println(e.getKey() + " " + e.getValue()));
            System.out.println();
        }
        sc.close();
    }
}