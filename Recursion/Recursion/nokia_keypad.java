import java.util.*;

public class nokia_keypad
{
    public static ArrayList<String>nokia(String ques,String[] keys)
    {
        if(ques.length() == 0)
        {
            ArrayList<String>base = new ArrayList<>();
            base.add(" ");
            return base;
        }
        char ch = ques.charAt(0);
        String rest = ques.substring(1);

        int idx = ch - '0';
        String word = keys[idx];

        ArrayList<String>finalans = new ArrayList<>();
        
        ArrayList<String>recAns = nokia(rest,keys);
        for(String s : recAns)
        {   for(int i = 0 ; i < word.length() ; i++)
            {
                finalans.add(word.charAt(i) + s);
            }  
        }
        return finalans;
    }
    public static void main(String[] args)
    {   
        String[] keys={".","ABC","DEF","GHI","JKL","MNO","PQRS","TU","VWX","YZ"};
        System.out.println(nokia("245",keys));
    }
}