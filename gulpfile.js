const gulp = require('gulp');
const git = require('gulp-git');
const download = require('gulp-download-files');
const decompress = require('gulp-decompress');
const del = require('del');
const vinylPaths = require('vinyl-paths');

gulp.task('clone-native', () => {
    return git.clone('https://github.com/weagle08/native-test.git', { args: './deps/native-test' }, (err) => {
        if (err != null) {
            console.log('git clone of native-test failed');
            console.log(err);
        }
    });
});

gulp.task('download-jpeg', () => {
    return download('http://ijg.org/files/jpegsr9d.zip')
        .pipe(gulp.dest('./deps'));
});

gulp.task('extract-jpeg', () => {
    return gulp.src('./deps/jpegsr9d.zip')
        .pipe(decompress({ strip: 1 }))
        .pipe(gulp.dest('./deps/jpeg'));
});

gulp.task('delete-jpeg', () => {
    return del('./deps/jpegsr9d.zip');
});

gulp.task('jpeg', gulp.series('download-jpeg', 'extract-jpeg', 'delete-jpeg'));

gulp.task('clean', () => {
    return gulp.src('./deps', { allowEmpty: true })
        .pipe(vinylPaths(del));
});