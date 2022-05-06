package sds;

import java.io.File;

public class RealImage implements Image {
    private String fileName;

    public RealImage(String fileName) {
        setFileName(fileName);
    }

    public String getFileName() {
        return fileName;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    @Override
    public void display() {
        if (loadFromDisk()) {
            System.out.println("Display image: " + fileName);
        } else {
            System.out.println("Not found image");
        }
    }

    private boolean loadFromDisk() {
        File f = new File(fileName);
        return f.exists() && !f.isDirectory();
    }
}
