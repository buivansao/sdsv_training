package sds;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class App {
    public static void main(String[] args) throws IOException {
//        SplitFile splitFile = new SplitFile("file.png", 5);
//        splitFile.createOutDir();
//        splitFile.split();

        FileMerge fileMerge = new FileMerge("file.png");
        fileMerge.mergeFile();
    }
}
