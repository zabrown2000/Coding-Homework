public class FileCountVisitor implements FileVisitor{
//since directory is the only class with multiple files, we only really need its implementation
//so the other classes can just return 1

    @Override
    public int visit(JpgFileDetails jpgFile) {
        return 1;
    }
    @Override
    public int visit(Mp3FileDetails mp3File) {
        return 1;
    }
    @Override
    public int visit(PptxFileDetails pptxFile) {
        return 1;
    }
    @Override
    public int visit(TxtFileDetails txtFile) {
        return 1;
    }
    @Override
    public int visit(DocxFileDetails docxFile) {
        return 1;
    }
    @Override
    public int visit(DirectoryDetails directory) {
        int count = 0;
        for (FileDetails file : directory) {
            count += file.accept(this);
        }
        return count;
    }

    @Override
    public int visit(HtmlFileDetails htmlFile) {
        return 1;
    }
}