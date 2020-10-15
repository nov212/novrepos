package ru.ncedu.novruzov.archivecomparator;

import java.io.FileInputStream;
import java.util.HashMap;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

/**
 * Collects information about files contained in a jar or zip file.
 * Stores name and checksum of each file. 
 * @author Novruzov Ilyas
 */

public class ArchiveExplorer {
    private HashMap<String, Long> files;
    private String path;
    /**
     * 
     * @param path path to archive 
     */
    public ArchiveExplorer(String path){
        this.path=path;
        files=new HashMap<>();
    }
    /**
     * find out information about name and checksum of each file in archive and keeps it in a HashMap 
     */
    public void explore(){
        if (path.endsWith(".jar") || path.endsWith(".zip")){
            try(ZipInputStream stream=new ZipInputStream(new FileInputStream(path))){
            ZipEntry entry;
            while ((entry=stream.getNextEntry())!=null){
                files.put(entry.getName(), entry.getCrc());
                stream.closeEntry();
            }
            stream.close();
            } catch (Exception ex){
                System.out.println(ex.getMessage());
            }
    }
        else throw new IllegalArgumentException("Illigal file extension");
}
    /**
     * 
     * @return name and checksum of each file in archive 
     */
    public HashMap<String, Long> getFiles(){
        return files;
    }
    /**
     * 
     * @return full name of archive 
     */
    public String getFullName(){
        return path;
    }
}
