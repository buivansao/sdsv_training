package sds;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class FileMerge {
    private String fileName;
    private List<String> listFiles = new ArrayList<String>();

    public FileMerge(String fileName) {
        setFileName(fileName);
    }

    public String getFileName() {
        return fileName;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    public void getListFiles() {
        File[] files = new File(fileName + "-parts").listFiles();

        assert files != null;
        for (File file : files) {
            if (file.isFile()) {
                listFiles.add(file.getName());
            }
        }
    }

    public void mergeFile() throws IOException {
        getListFiles();

        FileOutputStream fileOutputStreams = new FileOutputStream("new.png");
        for (String l : listFiles) {
            FileInputStream fileInputStream = new FileInputStream(new File(fileName + "-parts", l));
            fileOutputStreams.write(fileInputStream.read(new byte[fileInputStream.available()]));
            fileInputStream.close();
        }
        fileOutputStreams.close();
    }
}
