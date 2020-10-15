package ru.ncedu.novruzov.archivecomparator;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 * Compares two archives and finds out which files was updated, renamed, deleted or added and 
 * saves result in a text file
 * @author Novruzov Ilyas
 */

public class ArchiveComparator {
    private final HashMap<String, Long> firstArch;
    private final HashMap<String, Long> secondArch;
    private String firstPath;
    private String secondPath;
    private ArrayList<String> res;
    private final String FORMAT="%-30.30s | %-30.30s";

    
    public ArchiveComparator(ArchiveExplorer firstExp, ArchiveExplorer secondExp){
        firstArch=firstExp.getFiles();
        secondArch=secondExp.getFiles();
        firstPath=firstExp.getFullName();
        secondPath=secondExp.getFullName();
        res=new ArrayList<>();
    }
    /**
     * compares two archives
     */
    public void compare(){
        //find modified and renamed files
       for (Map.Entry<String,Long> first: firstArch.entrySet())
           for(Map.Entry<String, Long> second: secondArch.entrySet()){
           if (first.getKey().equals(second.getKey()) && !first.getValue().equals(second.getValue()))
               res.add(String.format(FORMAT, "* "+first.getKey(), "* "+second.getKey()));
           if (!first.getKey().equals(second.getKey()) && first.getValue().equals(second.getValue())){
               res.add(String.format(FORMAT, "? "+first.getKey(), "? "+second.getKey()));
           }
           }
           
       //find deleted files
       for (Map.Entry<String,Long> first: firstArch.entrySet()){
           if (!secondArch.containsKey(first.getKey()) && !secondArch.containsValue(first.getValue()))
               res.add(String.format(FORMAT, "- "+first.getKey(), ""));
       }
       //find new files
       for (Map.Entry<String,Long> second: secondArch.entrySet())
           if (!firstArch.containsKey(second.getKey()) && !firstArch.containsValue(second.getValue()))
               res.add(String.format(FORMAT, "", "+ "+second.getKey()));
       
}
    /**
     * Generates a text file with the results of comparsion.
     * <br>marks:
     * <br>*-updated file<br>
     * ?-presumably renamed<br>
     * +-added file<br>
     * --deleted file<br>
    */
    public void createResultFile (){

        String firstName=firstPath.substring(firstPath.lastIndexOf(File.separator)+1);
        String secondName=secondPath.substring(secondPath.lastIndexOf(File.separator)+1);
        File result=new File("compare_result.txt");
        try{
            FileWriter out=new FileWriter(result, false);
            String header=String.format(FORMAT, firstName, secondName);
            out.write(header);
            out.write("\r\n");
            out.write("-------------------------------+-------------------------------\r\n");
            for (String str : res){
                out.write(str);
                out.write("\r\n");
            }
            out.close();
        } catch (IOException ex){
            System.out.println(ex.toString());
        }
    }
}
