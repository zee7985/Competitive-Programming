import java.util.*;


public class knight_tour_Count
{
   public static int knight(int sr,int sc,int er,int ec,boolean [][]visited)
    {
        if( sr==er && sc==ec)
        {
            return 1;
        }

        int[][] dir={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{2,-1},{1,-2}};
        int count = 0 ;
        visited[sr][sc] = true;

        for(int d=0 ; d<dir.length ; d++)
        {
            int x=sr+dir[d][0];
            int y=sc+dir[d][1];

            if(x>=0 && y>=0 && x<visited.length && y<visited[0].length && !visited[x][y])
            {
                count+=knight(x,y,er,ec,visited);
            }
        }
        visited[sr][sc] = false;
        return count ;
    }
    public static void main(String [] args)
   {
      // boolean [5][5] visited
       int ans = knight(0,0,3,3,new boolean [4][4]);
       System.out.println("total number of ways:" + ans);
   }
}
 