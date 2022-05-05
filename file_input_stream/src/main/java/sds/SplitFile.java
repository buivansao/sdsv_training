package sds;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class SplitFile {
    private String fileName;
    private int nSegments;
    private List<String> chunkFileNames = new ArrayList<String>();

    public SplitFile(String fileName, int nSegments) {
        setFileName(fileName);
        setnSegments(nSegments);
    }

    public String getFileName() {
        return fileName;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    public int getnSegments() {
        return nSegments;
    }

    public void setnSegments(int nSegments) {
        this.nSegments = nSegments;
    }

    public boolean createOutDir() {
        return new File(fileName + "-parts").mkdir();
    }

    public void split() throws IOException {
        FileInputStream fileInputStream = new FileInputStream(new File(fileName));
        byte[] fileSize = new byte[(int) (getSize() / (nSegments - 1))];
        byte[] lastFileSize = new byte[(int) (getSize() % nSegments)];

        for (int i = 0; i < nSegments - 1; i++) {
            writeSegmentToFile(i, fileSize);
        }
        writeSegmentToFile(nSegments, lastFileSize);
        fileInputStream.close();
    }

    private void writeSegmentToFile(int index, byte[] data) throws IOException {
        FileOutputStream fileOutputStream = new FileOutputStream(new File(fileName + "-parts", getChunkFileName(index)));
        fileOutputStream.write(data);
        fileOutputStream.close();
    }

//    public void readIntoSegment(FileInputStream fis, Segment segment) throws IOException {
//        fis.read(segment.getSize());
//    }

    private long getSize() {
        return new File(fileName).length();
    }

    private String getChunkFileName(int index) {
        String fName = fileName + "-" + index;
        chunkFileNames.add(fName);
        return fName;
    }
}
