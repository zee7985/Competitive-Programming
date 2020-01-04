import java.util.Scanner;
import java.util.ArrayList;


public class returntype{
    
    public static Scanner scn=new Scanner(System.in);

    



    public static ArrayList<String> subSeq(String str){

    if(str.length()==0){
        ArrayList<String> base=new ArrayList<>();
        base.add(" ");
        return base;
    } 

    char ch=str.charAt(0);
    String rest=str.substring(1);

    ArrayList<String> recAns=subSeq(rest);

    ArrayList<String> myAns=new ArrayList<>();
    myAns.addAll(recAns);

    for(String s:recAns){
        myAns.add(ch+s);
    }
    return myAns;

    } 
    // public static String stringCompress(String ques){

    //     if(ques.length==1){
    //         return ques;
    //     }
    //     char ch=ques.charAt(0);
    //     String recAns=stringCompress(ques.substring(1));

    //     if(recAns.lenghth()>1 && ch==)

    // }


    public static String removeDuplicates(String ques){

        if(ques.length()==1){
            return ques;
        }
        char ch=ques.charAt(0);
        String recAns=removeDuplicates(ques.substring(1));
        if(ch==recAns.charAt(0)){
            return recAns;
        }
        return ch + recAns;
    }



    public static ArrayList<String> mazePath(int sr,int sc,int er,int ec)
    {
        if(sr==er && sc==ec)
        {
            ArrayList<String> ans=new ArrayList<>();
            ans.add("");
            return ans;
        }


        ArrayList<String> ans=new ArrayList<>();
        if(sc+1<=ec){
            ArrayList<String> Horizontal=mazePath(sr,sc+1,er,ec);
            for(String s:Horizontal){
                ans.add("H"+s);
            }
        }

        if(sr+1<=er){
            ArrayList<String> vertical=mazePath(sr+1,sc,er,ec);
            for(String s:vertical){
                ans.add("V"+s);
            }
        }
    return ans;

    }

     public static ArrayList<String> mazePathDiagonal(int sr,int sc,int er,int ec)
    {
        if(sr==er && sc==ec)
        {
            ArrayList<String> ans=new ArrayList<>();
            ans.add("");
            return ans;
        }



        ArrayList<String> ans=new ArrayList<>();
        if(sc+1<=ec){
            ArrayList<String> Horizontal=mazePathDiagonal(sr,sc+1,er,ec);
            for(String s:Horizontal){
                ans.add("H"+s);
            }
        }

        if(sr+1<=er){
            ArrayList<String> vertical= mazePathDiagonal(sr+1,sc,er,ec);
            for(String s:vertical){
                ans.add("V"+s);
            }
        }
        if(sc+1<=ec && sr+1<=er){
            ArrayList<String> diag = mazePathDiagonal(sr+1,sc+1,er,ec);
            for(String s:diag){
                ans.add("D"+s);
            }
        }
    return ans;

    }



    public static ArrayList<String> mazePathDiagonal_multistep(int sr,int sc,int er,int ec)      //maze path prob with 1,2,3,..... steps
    {
        if(sr==er && sc==ec)
        {
            ArrayList<String> ans=new ArrayList<>();
            ans.add("");
            return ans;
        }




        ArrayList<String> ans=new ArrayList<>();
        for(int i=1;sc+i<=ec;i++){
            ArrayList<String> Horizontal=mazePathDiagonal_multistep(sr,sc+i,er,ec);
            for(String s:Horizontal){
                ans.add("H"+i+s);
            }
        }

        for(int i=1;sr+i<=er;i++){
            ArrayList<String> vertical= mazePathDiagonal_multistep(sr+i,sc,er,ec);
            
            for(String s:vertical){
                ans.add("V"+i+s);
            }
        }

        for(int i=1;sc+i<=ec && sr+i<=er;i++){
            ArrayList<String> diag = mazePathDiagonal_multistep(sr+i,sc+i,er,ec);
            for(String s:diag){
                ans.add("D"+i+s);
            }
        }
    return ans;

    }


    public static ArrayList<String> floodFill(int sr,int sc,int er,int ec,boolean[][] visited)
    {
        if(sr==er && sc==ec)
        {
            ArrayList<String> ans=new ArrayList<>();
            ans.add("");
            return ans;
        }


        ArrayList<String> ans=new ArrayList<>();
        visited[sr][sc]=true;

        if(sr-1>=0 && !visited[sr-1][sc]){
            ArrayList<String> Upward=floodFill(sr-1,sc,er,ec,visited);
            for(String s:Upward){
                ans.add("U"+s);
            }
        }
        if(sc+1<=ec && !visited[sr][sc+1]){
            ArrayList<String> Right=floodFill(sr,sc+1,er,ec,visited);
            for(String s:Right){
                ans.add("R"+s);
            }
        }

        if(sr+1<=er  && !visited[sr+1][sc]){
            ArrayList<String> Downward=floodFill(sr+1,sc,er,ec,visited);
            for(String s:Downward){
                ans.add("D"+s);
            }
        }

        if(sc-1>=0 && !visited[sr][sc-1]){
            ArrayList<String> Left=floodFill(sr,sc-1,er,ec,visited);
            for(String s:Left){
                ans.add("L"+s);
            }
        }

        visited[sr][sc]=false;

       
    return ans;

    }
    public static boolean isValid(int x,int y, boolean[][] path,boolean[][] visited)
    {
        if(x>=0 && y>=0 && x<visited.length && y<visited[0].length && !path[x][y] && !visited[x][y]) return true;

        return false;
    }

    public static ArrayList<String> floodFillWithObstacle_eight_calls(int sr,int sc,int er,int ec,boolean[][] path,boolean[][] visited)
    {
        if(sr==er && sc==ec)
        {
            ArrayList<String> ans=new ArrayList<>();
            ans.add("");
            return ans;
        }
        int[][] dir={{1,0},{0,1},{0,-1},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
        String[] dirName={"D","R","U","L","1","3","4","2"};

        ArrayList<String> ans=new ArrayList<>();
        visited[sr][sc]=true;

        for(int d=0;d<dir.length;d++)
        {
            int x=sr + dir[d][0];
            int y=sc + dir[d][1];

            if(isValid(x,y,path,visited))
            {
                ArrayList<String> calls=floodFillWithObstacle_eight_calls(x,y,er,ec,path,visited);
                 for(String s:calls){
                ans.add(dirName[d] + s);
            }
            }
        }

        visited[sr][sc]=false;

       
    return ans;

    }

    public static boolean Valid(int x,int y,boolean[][] visited)
    {
        if(x>=0 && y>=0 && x<visited.length && y<visited[0].length && !visited[x][y]) return true;

        return false;
    }

    public static int KnightPath(int sr,int sc,int er,int ec,boolean[][] visited)   //Find total no. of path
                                                                                    //Horse move
    {
        if(sr==er && sc==ec)
        {
            return 1;
        }
        int[][] dir={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{2,-1},{1,-2}};

        int count=0;
      //  ArrayList<String> ans=new ArrayList<>();
        visited[sr][sc]=true;

        for(int d=0;d<dir.length;d++)
        {
            int x=sr + dir[d][0];
            int y=sc + dir[d][1];

            if(Valid(x,y,visited))
            {
            count+=KnightPath(x,y,er,ec,visited);
                 
            }
        }

        visited[sr][sc]=false;
        return count;

    }

    public static boolean Knight_Print_Path(int sr,int sc,int count,int boxSize,boolean[][] visited,int[][] ans)   //Knight should visit each cell exactly once
    {                                                                                                           //And then Print only one matrix out of all the possible matrix
        visited[sr][sc]=true;
        ans[sr][sc]=count;
                                                                                              
        if(count==boxSize-1)
        {
            for(int[] ar: ans){
                for(int ele : ar){
                    System.out.print(ele +" ");
                }
                System.out.println();
            }
            return true;
        }
        int[][] dir={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{2,-1},{1,-2}};
        boolean res=false;

        for(int d=0;d<dir.length && !res;d++)      
        {
            int x=sr + dir[d][0];
            int y=sc + dir[d][1];

            if(Valid(x,y,visited))
            {
             res =res || Knight_Print_Path(x,y,count+1,boxSize,visited,ans);
                 
            }
        }

        visited[sr][sc]=false;
        ans[sr][sc]=0;
        return res;

    }

    public static ArrayList<String> nokiaKeypad(String ques,String[] keys){

        if(ques.length()==0){
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;

        }

        // int[] num={1,2,3,4,5,6,7,8,9};
        // String[] alpha={"ABC","DEF","GHI","JKL","MNO","PQRS","TU","VWX","YZ"};

        char ch=ques.charAt(0);
        String rest=ques.substring(1);
        int idx=ch-'0';
        String word=keys[idx];
        ArrayList<String> myAns=new ArrayList<>();


        ArrayList<String> recAns=nokiaKeypad(rest,keys);
        for(String s:recAns){
            for(int i=0;i<word.length();i++){
                 myAns.add(word.charAt(i)+s);
            }
        
        
        }
        return myAns;

    }

    public static ArrayList<String> permute(String ques)
    {
        if(ques.length()==0) return new ArrayList<>();
        if(ques.length()==1){
            ArrayList<String> base=new ArrayList<>();
            base.add(ques);
            return base;

        }

        char ch=ques.charAt(0);
        String rest=ques.substring(1);

        ArrayList<String> recAns=permute(rest);

        ArrayList<String> myAns=new ArrayList<>();

        for(String s:recAns)
        {
            for(int i=0;i<=s.length();i++)
            {
                String ans=s.substring(0,i) + ch + s.substring(i);
                myAns.add(ans);
            }
        }
        return myAns;
    }


     public static ArrayList<String> encodingNumber(String ques){

        if(ques.length()==0){
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;

        }

        char ch=ques.charAt(0);
        ArrayList<String> myAns=new ArrayList<>();

        if(ch=='0'){
            return encodingNumber(ques.substring(1));
        }
        else
        {
           ArrayList<String> recAns=encodingNumber(ques.substring(1)); 
           for(String s:recAns){
               char ch1=(char)('a' + ch -'1');
               myAns.add(ch1 + s);
        }
        }

        if(ques.length()>1){

            char ch1=ques.charAt(1);
            int num=(ch - '0')*10 + (ch1 - '0');

            if(num<27){
                ArrayList<String> recAns=encodingNumber(ques.substring(2)); 
                for(String s:recAns){
                char ch2=(char)('a' + num -1);
                myAns.add(ch2 + s);

            }
        }
        }
        return myAns;
    }

    public static boolean isValidSudoku(int data,int row,int col,int[][] matrix)
    {
        for(int i=0;i<9;i++){
           //row
            if(matrix[row][i]!=data){
                return true;
            }
             //col
            if(matrix[col][i]!=data){
                return true;
            }
           
        }

        int rf=(row/3)*3;
         int cf=(col/3)*3;

         for(int i=0;i<3;i++){
             for(int j=0;j<3;j++){
                 if(matrix[rf+i][cf+j]!=data){
                     return true;
                 }
             }
         }
        return false;

    }

    // public static int soduko(int[][] matrix)
    // {
        
    // }





    public static void main(String[] args){
       // String str="ABCD";
        // System.out.println(subSeq(str));
        System.out.println(removeDuplicates("aaabbbcc"));
        ArrayList<String> ans=new ArrayList<>();

        // ans=mazePath(0,0,2,2);
        // for(String i : ans){
        //     System.out.println(i);

        // }


        // System.out.println(floodFill(0,0,2,2,new boolean[3][3]));
        // ans=floodFill(0,0,2,2,new boolean[3][3]);
        // for(String i : ans){
        //     System.out.println(i);

        // } 
        // boolean[][] path={{false,false,false,false},
        //                  {false,false,true,false},
        //                  {false,false,false,false},
        //                  {false,true,false,false},
        //                  {false,false,true,false}};

        // System.out.println(floodFillWithObstacle_eight_calls(0,0,3,3,,path,new boolean[4][4]));

       // System.out.println(KnightPath(0,0,3,3,new boolean[4][4]));

      //  System.out.println(Knight_Print_Path(0,0,0,49,new boolean[7][7],new int [7][7]));

    //   String[] keys={".","ABC","DEF","GHI","JKL","MNO","PQRS","TU","VWX","YZ"};
    //   System.out.println(nokiaKeypad("245",keys));

     //   System.out.println(permute("abc"));

        //  System.out.println(encodingNumber("1146"));

    }



}