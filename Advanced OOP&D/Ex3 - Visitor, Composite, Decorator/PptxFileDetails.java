public class PptxFileDetails extends FileDetails {
    private int slides;
    private int size;
    public PptxFileDetails(String path, String fileName, int slides, int size){
        super(path,fileName);
        this.slides=slides;
        this.size=size;
    }

    public int getSlides() {
        return slides;
    }

    public int getSize() {
        return size;
    }

    /**
     *
     * @param visitor the visitor to accept.
     * @return result of accept
     */
    @Override
    public int accept(FileVisitor visitor) {
        return visitor.visit(this);
    }
}
