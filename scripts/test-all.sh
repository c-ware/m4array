for tgt in scripts/vm-tests/*; do
    echo Testing on $tgt

    $tgt
done
