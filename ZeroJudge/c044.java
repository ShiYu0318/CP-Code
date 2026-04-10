import java.util.*;

public class c044
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        HashMap<Character, Integer> map = new HashMap<>();
        int n = sc.nextInt();
        sc.nextLine();
        for(int i=0; i<n; ++i)
        {
            String s = sc.nextLine();
            for(Character c : s.toCharArray())
            {
                if(Character.isLetter(c)) map.merge(Character.toUpperCase(c), 1, Integer::sum);
            }
        }
        map.entrySet().stream()
        .sorted(Map.Entry.<Character, Integer>comparingByValue(Comparator.reverseOrder())
        .thenComparing(Map.Entry.comparingByKey())).forEach(e -> System.out.println(e.getKey() + " " + e.getValue()));
        sc.close();
    }
}