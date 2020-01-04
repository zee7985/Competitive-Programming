import java.util.*;


public class graph{

    public static Scanner sc=new Scanner(System.in);
    public static ArrayList<Edge> []graph =new ArrayList[10];



    public static class Edge{
            int v=0;
            int w=0;

        Edge(int val,int wt){
            this.v=val;
            this.w=wt;
        }

        Edge(){

        }
    };

    public static void addedge(int u,int v,int w){

        if(u<0  || v<0 || u>graph.length || v>=graph.length)
            return;

    graph[u].add(new Edge(v,w));
    graph[v].add(new Edge(u,w));

    }

    public static void case1(){
        for(int i=0;i<graph.length;i++){
            graph[i]=new ArrayList<Edge>();
        }

        addedge(0,1,10);
        addedge(0,3,10);
        addedge(2,1,10);
        addedge(2,3,40);
        addedge(3,4,2);
        addedge(4,5,2);
        addedge(4,6,8);
        addedge(5,6,3);
        addedge(7,8,13);
        addedge(8,9,16);


    }

    public static void display(){
        for(int i=0;i<graph.length;i++){
            System.out.print(i + " =>");
            for(int j=0;j<graph[i].size();j++){
                System.out.print("("+graph[i].get(j).v + ", " + graph[i].get(j).w + "), ");
            } 
            System.out.println();
        }
    
    }



    public static class bfsOb{

        int vtx=0;
        int wtSofar=0;
        String pathSofar=" ";

        bfsOb(int vtx,int wtSofar,String pathSofar){
            this.vtx=vtx;
            this.wtSofar=wtSofar;
            this.pathSofar=pathSofar;

        }

        bfsOb(){

        }
    }

    public static void BFS_shortestPath(int src,boolean[] visited){

        int cycleNo=0;
        int length=0;
        int level=0;
        //int des=;
        int des=9;
        boolean ispath=false;
        


        LinkedList<bfsOb> queue =new LinkedList<>();
        bfsOb root=new bfsOb(src,0,src+ ""); 
        queue.addLast(root);
        queue.addLast(null);    //to find the level

        while(queue.size()!=-1)
        {
            bfsOb rpair =queue.removeFirst();


            //cycle
            if(visited[rpair.vtx]){
           System.out.println("cycle number:"  + cycleNo + " :" + rpair.pathSofar);
            cycleNo++;
            }

            //mark
            visited[rpair.vtx]=true;

            //destination
            if(rpair.vtx==des && !ispath){      // to print the shotest path ,for eg if a vertex can be visited by two path then only the shortest path will be printed
                System.out.println(rpair.pathSofar + "@" +rpair.wtSofar + "->" + level);
                ispath=true;
            }

            // add neighbour
            for(Edge e :graph[rpair.vtx]){
                if(!visited[e.v]) { //unmarked neighbour
                bfsOb pair=new bfsOb(e.v,rpair.wtSofar +e.w,rpair.pathSofar +"->"+e.v);
                queue.addLast(pair);
                }
            }
            if(queue.getFirst()==null){
                queue.removeFirst();
                queue.addLast(null);
                level++;
            }

    }
    }

    // public static void connected(){
    //     int comp=0;
    //     for(int i=0;i<graph.length;i++){
            
    //     }
        
    // }


    





    


  

    public static void main(String[] args){ 

        case1();
        //display();
        boolean[] vis=new boolean[graph.length];
         //BFS_shortestPath(0,vis);

        int comp=0;
        for(int i=0;i<graph.length;i++){
            if(!vis[i]){
                BFS_shortestPath(i,vis);
                comp++;
            }
        }
        
        System.out.println("dis-connected components: " + comp);
       

        
    }



}