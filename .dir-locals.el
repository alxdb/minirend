;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

((nil (eval . (progn
                 (setq cmake-ide-project-dir projectile-project-root)
                 (setq cmake-ide-build-dir (concat cmake-ide-project-dir "build"))))
      (cmake-ide-cmake-opts . "-DCMAKE_BUILD_TYPE=Debug")
      (fill-column . 120)))
