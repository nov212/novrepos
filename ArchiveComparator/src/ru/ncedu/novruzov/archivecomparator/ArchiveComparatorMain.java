package ru.ncedu.novruzov.archivecomparator;
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;

public class ArchiveComparatorMain {

    public static void main(String[] args) {
        String path1="";
        String path2="";
        if (args.length==0){
     JFileChooser chooser = new JFileChooser();
    FileNameExtensionFilter filter = new FileNameExtensionFilter(
        "ZiP & JAR Files", "zip", "jar");
    chooser.setFileFilter(filter);
    int returnVal = chooser.showOpenDialog(null);
    if(returnVal == JFileChooser.APPROVE_OPTION) 
       path1=chooser.getSelectedFile().getPath();
    returnVal = chooser.showOpenDialog(null);
    if(returnVal == JFileChooser.APPROVE_OPTION) 
       path2=chooser.getSelectedFile().getPath();
        }
        else
            if (args.length==2){
                path1=args[0];
                path2=args[1];
            }
            else throw new IllegalArgumentException();
    ArchiveExplorer exp1=new ArchiveExplorer(path1);
    ArchiveExplorer exp2=new ArchiveExplorer(path2);
    exp1.explore();
    exp2.explore();
    ArchiveComparator comporator=new ArchiveComparator(exp1, exp2);
    comporator.compare();
    comporator.createResultFile();

    
}
}
