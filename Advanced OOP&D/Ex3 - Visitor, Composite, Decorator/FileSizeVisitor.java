public class FileSizeVisitor implements FileVisitor{
//calling getSize for each file type

    @Override
    public int visit(JpgFileDetails jpgFile) {
        return jpgFile.getSize();
    }
    @Override
    public int visit(Mp3FileDetails mp3File) {
        return mp3File.getSize();
    }
    @Override
    public int visit(PptxFileDetails pptxFile) {
        return pptxFile.getSize();
    }
    @Override
    public int visit(TxtFileDetails txtFile) {
        return txtFile.getSize();
    }
    @Override
    public int visit(DocxFileDetails docxFile) {
        return docxFile.getSize();
    }
    @Override
    public int visit(DirectoryDetails directory) {
        int size = 0;
        for (FileDetails file : directory) {
            size += file.accept(this); //need to get size of entire directory so call accept on all children
        }
        return size;
    }
    @Override
    public int visit(HtmlFileDetails htmlFile) {
        return htmlFile.getSize();
    }
}

